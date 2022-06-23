#pragma once

namespace Engine
{
	//특정 시간에 표현해야할 뼈대 상태
	typedef struct tagKeyFrame
	{
		double Time;
		XMFLOAT3 vScale;
		XMFLOAT4 vRotation;
		XMFLOAT3 vPosition;
	}KEYFRAME;

	//텍스쳐 보관을 위한 구조체
	typedef struct MeshMaterial
	{
		class Texture* pMeshTexture[AI_TEXTURE_TYPE_MAX];
	}MATERIAL;

	typedef struct tagBoneDesc
	{
		XMFLOAT4X4		OffsetMatrix;	//뼈대를 정점의 로컬로 옮기기 위한 행렬
		class HierarchyNode*	pNode;	//뼈와 매칭되는 노드
	}BONEDESC;

	typedef struct tageVertex_Mesh
	{
		XMFLOAT3	vPosition;
		XMFLOAT3	vNormal;
		XMFLOAT2	vTexUV;
		XMFLOAT3	vTangent;
		XMUINT4		vBlendIndex;	//현재 정점에 영향을 주는 뼈(번호) 4개
		XMFLOAT4	vBlendWeight;   //뼈의 영향력(최대 1)
	}VTXMESH;

	//조명
	typedef struct tagLightDesc
	{
		enum TYPE { TYPE_DIRECTIONAL, TYPE_POINT, TYPE_END };
		TYPE			eType = TYPE_END;

		XMFLOAT3 vDirection; //방향성 광원 방향
		XMFLOAT3		vPosition;
		float			fRange;

		XMFLOAT4 vDiffuse;  // 난반사 광원에 대한 색
		XMFLOAT4 vAmbient;  // 환경광 (주변에서 반사되어 들어오는 빛)
		XMFLOAT4 vSpecular; // 정반사 광원에 대한 색(특정방향에서만 확인 가능한 것) ex)사과의 밝게빛나는 흰부분 
	}LIGHTDESC;

	//재질
	typedef struct tagMtrlDesc
	{
		XMFLOAT4 vDiffuse; //물체의 색
		XMFLOAT4 vAmbient;
		XMFLOAT4 vSpecular;
		XMFLOAT4 vEmissive; //스스로 발산 
	}MTRLDESC;
	//(L.vDiffuse * M.vDiffuse) * (V.Shade + (L.vAmbient * M.vAmbient)) 
	// + ((L.vSpecular * M.vSpecular) *fSpecular)
	// >물체의 기본 색 표시 후 정점의 그림자로 어둠표시 > 이렇게만 하면 어두우므로 환경광 추가 
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