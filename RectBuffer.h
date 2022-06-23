#pragma once
#include "VIBuffer.h"

namespace Engine
{
	class ENGINE_DLL RectBuffer final : public VIBuffer
	{
	public:
		explicit			RectBuffer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit			RectBuffer(const RectBuffer& rhs);
		virtual				~RectBuffer() = default;

	public:
		virtual HRESULT		Ready_Prototype(const _tchar* pShaderFilePath);
		virtual HRESULT		Ready(void* pArg) override;

	public:
		static RectBuffer*	Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext,const _tchar* pShaderFilePath);
		virtual Component*	Clone(void* pArg);
		virtual void		Free() override;
	};

}