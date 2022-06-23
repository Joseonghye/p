#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "RectBuffer.h"
#include "Renderer.h"
#include "Texture.h"

namespace Engine
{
	class ENGINE_DLL BaseUI : public GameObject
	{
	public:
		typedef struct tagUIDesc
		{
			_int    TextureSceneID;
			_tchar*	TextureName;
			_float fX;
			_float fY;
			_float fZ = 0.5f;
			_float fSizeX;
			_float fSizeY;

			_bool	bAnimation = false;
			_int	iAnimationCnt = 0;
		}UIDESC;
	public:
		explicit BaseUI(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit BaseUI(const BaseUI& rhs);
		virtual ~BaseUI() = default;

	public:
		virtual HRESULT Ready_Prototype();
		virtual HRESULT Ready(void* pArg);
		virtual _int	Update(_double TimeDelta);
		virtual _int	LateUpdate(_double TimeDelta);
		virtual HRESULT Render();

	public:
		virtual GameObject* Clone(void* pArg) = 0;
		virtual void Free() override;

	protected:
		RectBuffer*		m_pRectBuf;
		Renderer*		m_pRenderer;
		Texture*		m_pTexture;

		XMMATRIX		m_ProjMatrix;
		XMMATRIX		m_WorldMatrix;
	};

}