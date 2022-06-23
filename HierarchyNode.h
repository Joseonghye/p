#pragma once

#include "Base.h"
#include "AnimChannel.h"
namespace Engine 
{
	//뼈 정보 표현 
	class ENGINE_DLL HierarchyNode : public Base
	{
	public:
		explicit	HierarchyNode(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual		~HierarchyNode() = default;

	public:
		_uint		GetDepth() const { return m_iDepth; }
		const char* GetName() { return m_szBoneName; }
		_fmatrix	GetCombinedMatrix() const { return XMLoadFloat4x4(&m_CombinedTransformationMatrix); }
		_fmatrix	GetOffsetMatrix() { return XMLoadFloat4x4(&m_OffsetMatrix); }

		void		SetOffset(_fmatrix OffsetMatrix) { XMStoreFloat4x4(&m_OffsetMatrix, OffsetMatrix); }
	public:
		HRESULT		Ready(char* pBoneName, _fmatrix TransformationMatrix, _uint iDepth = 0, HierarchyNode* pParent = nullptr);
		void		UpdateCombinedTransformationMatrix(_uint iAniIndex);

		void		ResizeChannel(_uint iNumAnimation) { m_Channels.resize(iNumAnimation); }
		void		AddChannel(_uint iAniIndex, AnimChannel* pChannel) { m_Channels[iAniIndex] = pChannel; Safe_AddRef(pChannel); }

	public:
		static HierarchyNode*	Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, char* pBoneName, _fmatrix TransformationMatrix, _uint iDepth = 0, HierarchyNode* pParent = nullptr);
		virtual void			Free() override;

	public:
		char					m_szBoneName[MAX_PATH];
		HierarchyNode*			m_pParent;
		_uint					m_iDepth = 0;

		_float4x4				m_OffsetMatrix;
		_float4x4				m_TransformationMatrix;			// 자신의 상태
		_float4x4				m_CombinedTransformationMatrix; //부모의 상태 포함

		vector<class AnimChannel*>			m_Channels;

	private:
		ID3D11Device*			m_pDevice = nullptr;
		ID3D11DeviceContext*	m_pDeviceContext = nullptr;

	};

}