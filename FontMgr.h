#pragma once
#include "Base.h"

namespace Engine
{
	class CustomFont;
	class FontMgr : public Base
	{
		DECLARE_SINGLETON(FontMgr)
	public:
		explicit FontMgr();
		virtual ~FontMgr() = default;
	public:
		HRESULT AddFont(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const _tchar* pFontTag, const _tchar* pFontPath);
		HRESULT Render_Font(const _tchar* pFontTag, XMFLOAT2 vPos, const _tchar* pString, _fvector vColor);

	public:
		virtual void Free();

	private:
		typedef map<const _tchar*, CustomFont*>	FONT;
		FONT									m_Fonts;
	};

}