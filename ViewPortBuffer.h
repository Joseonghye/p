#pragma once

#include "VIBuffer.h"

namespace Engine {
	class ENGINE_DLL ViewPortBuffer final : public VIBuffer
	{
	protected:
		explicit ViewPortBuffer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit ViewPortBuffer(const ViewPortBuffer& rhs);
		virtual ~ViewPortBuffer() = default;
	public:
		virtual HRESULT Ready_Prototype(_float fX, _float fY, _float fSizeX, _float fSizeY, const _tchar* pShaderFilePath);
		virtual HRESULT Ready(void* pArg) override;

	public:
		static ViewPortBuffer* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, _float fX, _float fY, _float fSizeX, _float fSizeY, const _tchar* pShaderFilePath);
		virtual Component* Clone(void* pArg) override;
		virtual void Free() override;
	};
}