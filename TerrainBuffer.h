#pragma once
#include "VIBuffer.h"

namespace Engine
{
	class ENGINE_DLL TerrainBuffer final : public VIBuffer
	{
	public:
		explicit					TerrainBuffer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit					TerrainBuffer(const TerrainBuffer& rhs);
		virtual						~TerrainBuffer() = default;

	public:
		virtual HRESULT				Ready_Prototype(const _tchar* pShaderFilePath, const _tchar*pHeightmapPath);
		virtual HRESULT				Ready(void* pArg) override;

	public:
		static TerrainBuffer*		Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext,const _tchar* pShaderFilePath,const _tchar*pHeightmapPath);
		virtual Component*			Clone(void* pArg);
		virtual void				Free() override;

	private:
		_uint	m_iNumVerticesX;
		_uint	m_iNumVerticesZ;
	};

}