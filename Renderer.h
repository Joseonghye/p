#pragma once
#include "Component.h"

namespace Engine
{
	class ENGINE_DLL Renderer final: public Component
	{
	public:
		enum RENDER { RENDER_PRIORITY, RENDER_NONALPHA, RENDER_ALPHA, RENDER_UI, RENDER_END };

	private:
		explicit							Renderer(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual								~Renderer() = default;

	public:
		virtual HRESULT						Ready_Prototype();
		virtual HRESULT						Ready(void* pArg);

	public:
		HRESULT AddRenderGroup(RENDER eRenderID, class GameObject* pGameObject);
		HRESULT DrawRenderGroup();

	private:
		HRESULT Render_Priority();
		HRESULT Render_NonAlpha();
		HRESULT Render_Alpha();
		HRESULT Render_UI();
	private:
		HRESULT Render_LightAcc();
		HRESULT Render_Blend();

	public:
		static Renderer*					Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual Component*					Clone(void* pArg) override;
		virtual void						Free() override;

	private:
		list<class GameObject*>			m_RenderGroup[RENDER_END];
		typedef list<class GameObject*>	RENDERGROUP;

	private:
		class TargetMgr*				m_pTargetMgr = nullptr;
		class ViewPortBuffer*			m_pVIBuffer = nullptr;
	};

}