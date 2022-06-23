#pragma once
#include "Base.h"

namespace Engine
{
	class Component;

	class ENGINE_DLL GameObject abstract: public Base
	{
	protected:
		explicit			GameObject(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit			GameObject(const GameObject& rhs);
		virtual				~GameObject() = default;

	public:
		Component*			GetComponent(const _tchar* pComponentTag);
	//	Component*			GetComponent(Component::COMPONENT_ID ID);

		void				SetActive(_bool set) { m_isActive = set; }
		void				SetTag(GameObjectTag tag)  { m_eTag = tag; }
		void				SetName(string name)  { m_strName = name; }
		
		_bool				GetActive() { return m_isActive; }
		_bool				GetDestroy() { return m_isDestroy; }
		GameObjectTag		GetTag() { return m_eTag; }
		string				GetName() { return m_strName; }
	public:
		virtual HRESULT		Ready_Prototype(); //원형 생성
		virtual HRESULT		Ready(void* pArg); //복사본 생성

		virtual	_int		Update(_double TimeDelta);
		virtual _int		LateUpdate(_double TimeDelta);

		virtual HRESULT		Render();

	protected:
		virtual HRESULT		SetUpComponents(_uint iSceneIndex, const _tchar* pPrototypeTag, const _tchar* pComponentTag, class Component** ppOut, void* pArg = nullptr);
	//	virtual HRESULT		SetUpComponents(_uint iSceneIndex, const _tchar* pPrototypeTag, class Component** ppOut, void* pArg = nullptr);
	public:
		virtual GameObject* Clone(void* pArg) = 0;
		virtual void		Free() override;

	protected:
		ID3D11Device*										m_pDevice;
		ID3D11DeviceContext*								m_pDeviceContext;

		_bool												m_isActive = true;
		_bool												m_isDestroy = false;
		GameObjectTag										m_eTag;
		string												m_strName;

	protected:
		unordered_map<const _tchar*, class Component*>		m_Components;
	//	vector<class Component*>							m_Components;
	};

}