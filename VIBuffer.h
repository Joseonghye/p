#pragma once
#include "Component.h"

namespace Engine
{
	class ENGINE_DLL VIBuffer abstract: public Component
	{
	public:
		typedef struct tagEffectDesc
		{
			ID3D11InputLayout*		 pInputLayout = nullptr;
			LPD3D11EFFECTPASS		 pPass = nullptr;
		}EFFECTDESC;
	protected:
		explicit			VIBuffer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit			VIBuffer(const VIBuffer& rhs);
		virtual				~VIBuffer() = default;

	public:
		virtual HRESULT		Ready_Prototype() override;
		virtual HRESULT		Ready(void* pArg) override;

		virtual HRESULT		Render(_uint iPassIndex);

	public:
		HRESULT				SetUpValueOnShader(const char* pConstantName, void* pData, _uint iSize);
		HRESULT				SetUpTextureOnShader(const char* pConstantName, class Texture* pTexture, _uint iTextureIndex = 0);
		HRESULT				SetUpTextureOnShader(const char* pConstantName, ID3D11ShaderResourceView* pSRV);
	protected:
		HRESULT				CreateVertexBuffer();
		HRESULT				CreateIndexBuffer();

		HRESULT				CompileShaderFiles(const _tchar* pShaderFilePath ,D3D11_INPUT_ELEMENT_DESC* pElementDesc, _uint iNumElements);

	public:
		virtual Component*	Clone(void* pArg) = 0;
		virtual void		Free() override;

	protected:
		ID3D11Buffer*			 m_pVB;
		D3D11_BUFFER_DESC		 m_VBDesc;
		D3D11_SUBRESOURCE_DATA	 m_VBSubresourceData;
		_uint					 m_iStride; //정점하나의 바이트 크기
		_uint					 m_iNumVertices;
		void*					 m_pVertices = nullptr;

	protected:
		ID3D11Buffer*			 m_pIB;
		D3D11_BUFFER_DESC		 m_IBDesc;
		D3D11_SUBRESOURCE_DATA	 m_IBSubresourceData;
		_uint					 m_IndicesByte; //도형 하나를 그리기 위한 인덱스 바이트 
		_uint					 m_iNumPrimitive; //도형 갯수 
		_uint					 m_iNumIndicesPrimitive; //도형 하나를 그리기 위한 인덱스 갯수
		DXGI_FORMAT				 m_eFormat;
		D3D11_PRIMITIVE_TOPOLOGY m_ePrimitiveTopology; //그려질 모양

	protected:
		LPD3D11EFFECT			m_pEffect;
		vector<tagEffectDesc* > m_EffectDescs;

		
	};

}