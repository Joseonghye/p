#pragma once
#include "Base.h"

namespace Engine {

	class RenderTarget final : public Base
	{
	private:
		RenderTarget(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual ~RenderTarget() = default;
	public:
		ID3D11RenderTargetView* GetRTV() { return m_pRTV;	}
		ID3D11ShaderResourceView* GetSTV() { return m_pSRV;	}
	public:
		HRESULT Ready(_uint iWidth, _uint iHeight, DXGI_FORMAT eFormat, _float4 vClearColor);
		HRESULT Clear();

#ifdef _DEBUG
	public:
		HRESULT Ready_DebugBuffer(_float fX, _float fY, _float fSizeX, _float fSizeY);
		HRESULT Render_DebugBuffer();
#endif // _DEBUG

	private:
		ID3D11Device*			m_pDevice = nullptr;
		ID3D11DeviceContext*	m_pDeviceContext = nullptr;

	private:
		ID3D11Texture2D*			m_pTexture = nullptr;
		ID3D11RenderTargetView*		m_pRTV = nullptr;
		ID3D11ShaderResourceView*	m_pSRV = nullptr;
		_float4						m_vClearColor;

#ifdef _DEBUG
	private:
		class ViewPortBuffer*		m_pDebugBuffer = nullptr;
#endif // _DEBUG

	public:
		static RenderTarget* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, _uint iWidth, _uint iHeight, DXGI_FORMAT eFormat, _float4 vClearColor);
		virtual void Free() override;
	};

}