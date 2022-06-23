#pragma once

namespace Engine
{
	//Ư�� �ð��� ǥ���ؾ��� ���� ����
	typedef struct tagKeyFrame
	{
		double Time;
		XMFLOAT3 vScale;
		XMFLOAT4 vRotation;
		XMFLOAT3 vPosition;
	}KEYFRAME;

	//�ؽ��� ������ ���� ����ü
	typedef struct MeshMaterial
	{
		class Texture* pMeshTexture[AI_TEXTURE_TYPE_MAX];
	}MATERIAL;

	typedef struct tagBoneDesc
	{
		XMFLOAT4X4		OffsetMatrix;	//���븦 ������ ���÷� �ű�� ���� ���
		class HierarchyNode*	pNode;	//���� ��Ī�Ǵ� ���
	}BONEDESC;

	typedef struct tageVertex_Mesh
	{
		XMFLOAT3	vPosition;
		XMFLOAT3	vNormal;
		XMFLOAT2	vTexUV;
		XMFLOAT3	vTangent;
		XMUINT4		vBlendIndex;	//���� ������ ������ �ִ� ��(��ȣ) 4��
		XMFLOAT4	vBlendWeight;   //���� �����(�ִ� 1)
	}VTXMESH;

	//����
	typedef struct tagLightDesc
	{
		enum TYPE { TYPE_DIRECTIONAL, TYPE_POINT, TYPE_END };
		TYPE			eType = TYPE_END;

		XMFLOAT3 vDirection; //���⼺ ���� ����
		XMFLOAT3		vPosition;
		float			fRange;

		XMFLOAT4 vDiffuse;  // ���ݻ� ������ ���� ��
		XMFLOAT4 vAmbient;  // ȯ�汤 (�ֺ����� �ݻ�Ǿ� ������ ��)
		XMFLOAT4 vSpecular; // ���ݻ� ������ ���� ��(Ư�����⿡���� Ȯ�� ������ ��) ex)����� ��Ժ����� ��κ� 
	}LIGHTDESC;

	//����
	typedef struct tagMtrlDesc
	{
		XMFLOAT4 vDiffuse; //��ü�� ��
		XMFLOAT4 vAmbient;
		XMFLOAT4 vSpecular;
		XMFLOAT4 vEmissive; //������ �߻� 
	}MTRLDESC;
	//(L.vDiffuse * M.vDiffuse) * (V.Shade + (L.vAmbient * M.vAmbient)) 
	// + ((L.vSpecular * M.vSpecular) *fSpecular)
	// >��ü�� �⺻ �� ǥ�� �� ������ �׸��ڷ� ���ǥ�� > �̷��Ը� �ϸ� ��ο�Ƿ� ȯ�汤 �߰� 
	// 

	typedef struct tagVertex_Matrix
	{
		XMFLOAT4		vRight;
		XMFLOAT4		vUp;
		XMFLOAT4		vLook;
		XMFLOAT4		vPosition;
	} VTXMATRIX;

	typedef struct tagVertex_Point
	{
		XMFLOAT3		vPosition;
		XMFLOAT2		vPSize;
	} VTXPOINT;

	typedef struct tagVertex_Texture
	{
		XMFLOAT3	vPosition;
		XMFLOAT2	vTexUV;
	}VTXTEX;

	typedef struct tagVertex_NormalTexture
	{
		XMFLOAT3	vPosition;
		XMFLOAT3	vNormal;
		XMFLOAT2	vTexUV;
	}VTXNORTEX;
	typedef struct tagVertex_Texture_Cube
	{
		XMFLOAT3	vPosition;
		XMFLOAT3	vTexUV;
	}VTXCUBETEX;

	typedef struct tagLineIndices_16
	{
		unsigned short	_0, _1;
	}LINEINDICES16;

	typedef struct tagFaceIndices_16
	{
		unsigned short	_0, _1, _2;
	}FACEINDICES16;

	typedef struct tagFaceIndices_32
	{
		unsigned long	_0, _1, _2;
	}FACEINDICES32;
}