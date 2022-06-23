#pragma once

#include "VIBuffer.h"

namespace Engine {

	class ENGINE_DLL Model final :public VIBuffer
	{
	public:
		enum MESHTYPE {TYPE_NONE, TYPE_ANIM,TYPE_END};
	private:
		explicit Model(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit Model(const Model& rhs);
		virtual ~Model() = default;

	public:
		_uint GetNumMeshContainer() { return m_MeshContainers.size(); }
		_bool GetCurrentAnimationEnd();
		_fmatrix GetPivotMatrix() { return XMLoadFloat4x4(&m_PivotMatrix); }
		class HierarchyNode* GetBoneNode(const char* pName) { return FindHierarchyNode(pName); }
		
	public:
		HRESULT Ready_Prototype(const char* pMeshFilePath, const char* pMeshName, const _tchar* pShaderFilePath, _fmatrix PivotMatrix, MESHTYPE eMeshType);
		HRESULT Ready(void* pArg) override;

		HRESULT	BindBuffers();
		HRESULT	UpdateCombinedTransformationMatrix(_double TimeDelta); //뼈대 렌더링을 위한 최종행렬 
		//void	AnimationInterpolation(_double TimeDelta);
		HRESULT Render(_uint iMeshContainerIndex, _uint iPassIndex);

		void SetUpAnimationIndex(_uint iAniIndex);
		HRESULT SetUpTextureOnShader(const char* pConstantName, _uint iMeshContainerIndex, aiTextureType eTextureType);

	private:
		HRESULT	ReserveVIData();
		HRESULT CreateMeshContainer(); //메쉬 정보 
		HRESULT CreateMaterial();
		HRESULT CreateVIBuffer();
		HRESULT CompileShaderFiles(const _tchar* pShaderFilePath);

		HRESULT CreateHierarchyNode(aiNode* pNode, class HierarchyNode* pParent = nullptr, _uint iDepth = 0);
		HRESULT	CreateSkinned();
		HRESULT CreateAnimation();

		void SetHierarchyNode(const aiScene* scene, aiNode* node, class HierarchyNode* parents, _uint depth);

	private:
		class HierarchyNode* FindHierarchyNode(const char* pName);

	public:
		static Model* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext,
			const char* pMeshFilePath, const char* pMeshName, const _tchar* pShaderFilePath, _fmatrix PivotMatrix, MESHTYPE eMeshType);
		virtual Component* Clone(void* pArg) override;
		virtual void Free() override;

	private:
		const aiScene*		m_pScene;
		Assimp::Importer	m_Importer;

		_uint				m_iCurAni;
		MESHTYPE			m_eMeshType;

		_float4x4			m_PivotMatrix;
		FACEINDICES32*		m_pFaceIndices;
		char				m_szMeshFilePath[MAX_PATH];

	private:
		string									m_strModelName;
		vector<class MeshContainer*>			m_MeshContainers;
		typedef vector<class MeshContainer*>	MESHCONTAINERS;

		vector<MATERIAL*>						m_Materials;
		typedef	vector<MATERIAL*>				METARIALS;

		vector<class HierarchyNode*>			m_HierarchyNodes;
		typedef vector<class HierarchyNode*>	HIERARCHYNODES;

		vector<class Animation*>				m_Animations;
		typedef vector<class Animation*>		ANIMATIONS;
	};

}