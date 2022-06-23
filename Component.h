#pragma once
#include "Base.h"

namespace Engine
{
	class ENGINE_DLL Component abstract : public Base
	{
//	public:
//		enum COMPONENT_ID { TRANSFORM,RENDERER,COLLIDER,MESH };
	public:
		explicit Component(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);//, COMPONENT_ID ID);
		explicit Component(const Component& rhs);
		virtual ~Component() = default;
	public:
		virtual HRESULT Ready_Prototype();
		virtual HRESULT Ready(void* pArg);
	
	public:
		void SetOwner(class GameObject* pOwner) { m_pOwner = pOwner; }

	public:
		virtual Component* Clone(void* pArg) = 0;
		virtual void Free() override;

	protected:
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;

		_bool					m_isCloned;
//		COMPONENT_ID			m_eID;
		class GameObject*		m_pOwner;
	};
}