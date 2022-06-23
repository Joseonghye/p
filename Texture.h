#pragma once

#include "Component.h"

namespace Engine
{
	class ENGINE_DLL Texture final :public Component
	{
	private:
		explicit Texture(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit Texture(const Texture& rhs);
		virtual ~Texture() = default;

	public:
		ID3D11ShaderResourceView* GetShaderResourceView(_uint index) { return m_Textures[index]; }

	public:
		virtual HRESULT Ready_Prototype(const _tchar* pTextureFilePath, _uint iNumTextures);
		virtual HRESULT Ready(void* pArg) override;

	public:
		static Texture* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const _tchar* pTextureFilePath, _uint iNumTextures = 1);
		virtual Component*	Clone(void* pArg) override;
		virtual void Free() override;

	private://쉐이더 사용을 위한 리소스 타입
		vector<ID3D11ShaderResourceView*>	m_Textures;
		typedef vector<ID3D11ShaderResourceView*>	TEXTURES;
			
	};

}