#include "Shader_RenderState.hpp"

//cbuffer : ��� �޸� ���� / ��� ������������ '��� ���̺�'�̶� �θ�
// > ���? ���̴� ���������� ���ȭ �Ǿ��ִ�.(�̿�O,����X) > Ŭ���̾�Ʈ�� ���� ���� �޾ƿ�
//�������� �̸��� ������ ������ ������
//���� �Ǵ� Ÿ�̹��� ���� �ֵ鳢�� ��� �δ� ���� ���� 

cbuffer Matrices
{
	matrix g_WorldMatrix;
	matrix g_ViewMatrix;
	matrix g_ProjMatrix;
};

cbuffer CamDesc
{
	vector g_vCamPosition;
};

cbuffer BrushDesc
{
	vector g_vBrushPosition = vector(20.f, 0.f, 10.f, 1.f);
	float g_fRadius = 10.f;
};

cbuffer LightDesc
{
	vector g_vLightDirection = vector(1.f, -1.f, 1.f,0.f);
	vector g_vLightDiffuse = vector(1.f, 1.f, 1.f, 1.f);
	vector g_vLightAmbient = vector(1.f, 1.f, 1.f, 1.f);
	vector g_vLightSpecular = vector(1.f, 1.f, 1.f, 1.f);
};

cbuffer MtrlDesc
{
	vector g_vMtrlDiffuse = vector(1.f, 1.f, 1.f, 1.f);
	vector g_vMtrlAmbient = vector(0.4f, 0.4f, 0.4f, 1.f);
	vector g_vMtrlSpecular = vector(1.f, 1.f, 1.f, 1.f);
};

texture2D g_DiffuseSourceTexture;
texture2D g_DiffuseDestTexture;
texture2D g_FilterTexture;
texture2D g_BrushTexture;

//���� ���ø�

sampler DefaultSampler = sampler_state
{
	filter = min_mag_mip_linear;
	AddressU = wrap;
	AddressV = wrap;
};

/*
1. m_pDeviceContext->DrawIndexed()
2. �ε����� ������ �ִ� ���� ������ �������۷κ��� ���´�.
3. VS_MAIN�Լ��� ȣ���ϸ鼭 ������ ���� ������ �ϳ��� �������ش�.
*/

struct VS_IN
{
	float3	vPosition: POSITION;
	float3	vNormal: NORMAL;
	float2	vTexUV: TEXCOORD0;
};

struct VS_OUT
{
	float4	vPosition : SV_POSITION;
	float2	vTexUV : TEXCOORD0;
	float	fShade : TEXCOORD1; //���
	float	fSpecular : TEXCOORD2;
	float4	vWorldPos : TEXCOORD3;
};

VS_OUT VS_MAIN(VS_IN In)
{
	//VS_IN :���� ���ۿ� ���ǵǾ��ִ� ���������� �״�� �޾ƿ� �� (����)
	
	//1. ���� �����̽� ��ȯ 
	matrix matWV, matWVP;

	matWV = mul(g_WorldMatrix, g_ViewMatrix);
	matWVP = mul(matWV, g_ProjMatrix);

	//2. �ȼ��� ������ ������ ����
	VS_OUT Out = (VS_OUT)0;
	
	Out.vPosition = mul(vector(In.vPosition, 1.f), matWVP);//���� w �����⸦ ���ؼ� �佺���̽��� ����
	Out.vTexUV = In.vTexUV;

	vector WorldNormal = mul(vector(In.vNormal, 0.f), g_WorldMatrix);
	vector WorldPosition = mul(vector(In.vPosition, 1.f), g_WorldMatrix);

	//����
	Out.fShade = saturate(dot(normalize(g_vLightDirection)* -1.f, normalize(WorldNormal)));
	// == Out.fShade = max(dot(normalize(g_vLightDirection)* -1.f, normalize(WorldNormal)), 0.f);
	// ���� �� Ȥ�� 0���� ���� ��� 0

	vector vReflect = reflect(normalize(g_vLightDirection), normalize(WorldNormal));
	vector vLook = WorldPosition - g_vCamPosition;
	Out.fSpecular = pow(saturate(dot(normalize(vReflect)*-1.f, normalize(vLook))),30.f);

	//�̷��� �߰��ϸ� ���� ��ǥ ���� ���� 
	//Out.vWorldPosition = mul(vector(In.vPosition, 1.f), g_WorldMatrix);

	Out.vWorldPos = WorldPosition;

	return Out;
}
/* ���ؽ� ���̴��� ���� �� ,
 SV_POSITION�� ���ؼ��� ���� ���� (w ������ xyz�� ���� > SV_POSITION ������ flaot4������)
 (2���� ���� �����̽��� �̵�)
 ����Ʈ�� ��ȯ (������� ��ǥ�� �̵�)
 �����Ͷ����� (�ѷ��׿��� ���� ������ �������� �ȼ� ���� ����)
*/

struct PS_IN
{
	//SV_POSITION�� ���ؼ��� ���� ����. (w ������ xyz�� ���� > SV_POSITION ������ flaot4������.)
	float4	vPosition: SV_POSITION;
	float2	vTexUV: TEXCOORD0;
	float	fShade : TEXCOORD1; //���
	float	fSpecular: TEXCOORD2; 
	float4	vWorldPos : TEXCOORD3;

	//���� ��ġ�� ������ ���� ��� (�ø�ƽ�� POSITION�����ϸ� ������ ����ϹǷ� �ȵ�)
	//VS_OUT�� ���� �ؾ��ϹǷ� ������ �߰��ؾ���
	//float4  vWorldPosition:TEXCOORD1; << ���� ��ġ�� �������� ���������ؼ� �����Ե� 
};
struct PS_OUT
{
	vector		vColor : SV_TARGET0;
};

PS_OUT PS_MAIN(PS_IN In)
{
	/*
	if(In.vWorldPosition.y < 5.f)
	  vColor = BULE;
	> �̷������� ������ǥ���� 5�Ʒ��� �Ķ��� ��������
	*/

	PS_OUT		Out = (PS_OUT)0;

	vector vSourDiffuse = g_DiffuseSourceTexture.Sample(DefaultSampler,In.vTexUV * 10.f);
	vector vDestDiffuse = g_DiffuseDestTexture.Sample(DefaultSampler, In.vTexUV * 20.f);
	vector vFilterColor = g_FilterTexture.Sample(DefaultSampler, In.vTexUV);
	
	//vector vBrushColor = g_BrushTexture.Sample(DefaultSampler, In.vTexUV);
	vector vBrushColor = (vector)0;

	if (g_vBrushPosition.x - g_fRadius <= In.vWorldPos.x && In.vWorldPos.x < g_vBrushPosition.x + g_fRadius &&
		g_vBrushPosition.z - g_fRadius <= In.vWorldPos.z && In.vWorldPos.z < g_vBrushPosition.z + g_fRadius)
	{
		float2		vTexUV = float2((In.vWorldPos.x - (g_vBrushPosition.x - g_fRadius)) / (2.f * g_fRadius),
			((g_vBrushPosition.z + g_fRadius) - In.vWorldPos.z) / (2.f * g_fRadius));
		vBrushColor = g_BrushTexture.Sample(DefaultSampler, vTexUV);
	}

	vector	vDiffuse = vSourDiffuse * vFilterColor.r + vDestDiffuse * (1.f - vFilterColor.r) + vBrushColor;


	Out.vColor = (g_vLightDiffuse * vDiffuse) * saturate(In.fShade + (g_vLightAmbient * g_vMtrlAmbient))
		+ ((g_vLightSpecular * g_vMtrlSpecular) *In.fSpecular);

	return Out;
}

technique11	DefaultTechnique
{
	pass Normal
	{
		SetRasterizerState(CullMode_Default);
		SetDepthStencilState(ZDefault, 0);
		SetBlendState(BlendDisable, vector(0.f, 0.f, 0.f, 0.f), 0xffffffff);

		VertexShader = compile vs_5_0 VS_MAIN();
		GeometryShader = NULL;
		PixelShader = compile ps_5_0  PS_MAIN();
	}
}