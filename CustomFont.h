#pragma once
#include "Base.h"

namespace Engine
{
	class CustomFont final:	public Base
	{
	public:
		explicit CustomFont(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual ~CustomFont() = default;
	public:
		HRESULT Ready_CustomFont(const _tchar* pFontPath);
		HRESULT Render_CustomFont(XMFLOAT2 vPos, const _tchar* pString, _fvector vColor);
	
	public:
		static CustomFont* Create(ID3D11Device* pGraphic_Device, ID3D11DeviceContext* pGraphic_Device_Context, const _tchar* pFontPath);
		virtual void Free();

	private:
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;
	private:
		DirectX::SpriteBatch*	m_pSpriteBatch;
		DirectX::SpriteFont*	m_pSpriteFont;
	
	};

}