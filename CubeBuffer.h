#pragma once
#include "VIBuffer.h"

namespace Engine
{
	class ENGINE_DLL CubeBuffer final : public VIBuffer
	{
	public:
		explicit			CubeBuffer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit			CubeBuffer(const CubeBuffer& rhs);
		virtual				~CubeBuffer() = default;

	public:
		virtual HRESULT		Ready_Prototype(const _tchar* pShaderFilePath);
		virtual HRESULT		Ready(void* pArg) override;

	public:
		static CubeBuffer*		Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext,const _tchar* pShaderFilePath);
		virtual Component*	Clone(void* pArg);
		virtual void		Free() override;
	};

}