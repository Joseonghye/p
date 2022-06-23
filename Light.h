#pragma once
#include "Base.h"

namespace Engine {
	class Light final :	public Base
	{
	private:
		explicit		Light(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual			~Light() = default;

	public:
		const LIGHTDESC* GetLightDesc() { return &m_LightDesc; }
	public:
		HRESULT			Ready(const LIGHTDESC& LightDesc);
		HRESULT			Render();

	public:
		static Light*	Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext,const LIGHTDESC& LightDesc);
		virtual void	Free() override;
	
	private:
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;

		LIGHTDESC				m_LightDesc;
		class ViewPortBuffer*	m_pVIBuffer;
	};

}