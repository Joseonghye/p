#pragma once

#include "VIBuffer.h"

namespace Engine {
	class ENGINE_DLL PointInstanceBuffer final : public VIBuffer
	{
	protected:
		explicit PointInstanceBuffer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit PointInstanceBuffer(const PointInstanceBuffer& rhs);
		virtual ~PointInstanceBuffer() = default;
	public:
		virtual HRESULT Ready_Prototype(const _tchar* pShaderFilePath, _uint iNumInstance);
		virtual HRESULT Ready(void* pArg) override;
		virtual HRESULT Render(_uint iPassIndex);

	public:
		void Update(_double TimeDelta);

	private:
		_uint			m_iNumInstance = 0;

		ID3D11Buffer*				m_pVBInstance = nullptr;
		D3D11_BUFFER_DESC			m_VBInstDesc;
		D3D11_SUBRESOURCE_DATA		m_VBInstSubresourceData;
		_uint						m_iInstStride = 0; /*정점하나의 바이트 크기. */
		_uint						m_iInstNumVertices = 0;
		_double*					m_pDropSpeed = nullptr;

		vector<_float3>						m_vecDir;

	public:
		static PointInstanceBuffer* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const _tchar* pShaderFilePath, _uint iNumInstance);
		virtual Component* Clone(void* pArg) override;
		virtual void Free() override;
	};

}