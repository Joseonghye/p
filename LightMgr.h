#pragma once
#include "Base.h"

namespace Engine {
	class LightMgr final :public Base
	{
		DECLARE_SINGLETON(LightMgr)
	public:
		explicit LightMgr();
		virtual ~LightMgr() = default;

	public:
		const LIGHTDESC* GetLightDesc(_uint iIndex = 0);
	public:
		HRESULT AddLight(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const LIGHTDESC& LightDesc);
		HRESULT Render_Lights();

	public:
		virtual void Free()override;

	private:
		typedef list<class Light*>	LIGHTS;
		LIGHTS						m_Lights;
	
	};

}