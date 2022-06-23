#pragma once

#include "Base.h"

namespace Engine{
	class HierarchyNode;

class MeshContainer final :public Base
{
public:
	typedef struct tagMeshContainerDesc
	{
		_uint	iMaterialIndex;
		_uint	iStartVertexIndex; //시작 정점(전체 정점 기준)
		_uint	iStartFaceIndex;
		_uint	iNumFaces;
		const char* strName;
	}MESHDESC;

public:
	MeshContainer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
	MeshContainer(const MeshContainer& rhs);
	virtual ~MeshContainer() = default;

public:
	const char*				GetMeshName() { return m_MeshDesc.strName; }
	_uint					GetMaterialIndex() const { return m_MeshDesc.iMaterialIndex; }
	MESHDESC				GetMeshDesc() const { return m_MeshDesc; }
	HierarchyNode*			GetParent() { return m_pParent; }
	_bool					isBoneEmpty() { return m_Bones.empty(); }

	void					SetParent(HierarchyNode* pParent) { m_pParent = pParent; }
public:
	HRESULT					Ready(const MESHDESC& MeshDesc);
	HRESULT					Render();

	HRESULT					AddBoneDesc(BONEDESC* pBoneDesc);
	void					SetUpBoneMatrice(_matrix* pBoneMatrices, _fmatrix PivotMat);
public:
	static MeshContainer*	Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const MESHDESC& MeshDesc);
	MeshContainer*			Clone();
	virtual void			Free() override;

private:
	ID3D11Device*				m_pDevice;
	ID3D11DeviceContext*		m_pDeviceContext;

private:
	HierarchyNode*		m_pParent = nullptr;
	MESHDESC					m_MeshDesc;
	vector<BONEDESC*>			m_Bones;
	typedef vector<BONEDESC*>	BONES;
	
};

}