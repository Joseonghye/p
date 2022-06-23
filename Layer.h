#pragma once
#include "Base.h"

namespace Engine
{
	class Layer final: public Base
	{
	private:
		Layer();
		virtual ~Layer() = default;

	public:
		class Component* GetComponent(const _tchar* pComponentTag, _uint iIndex);
		list<class GameObject*> GetGameObjects();
	public:
		HRESULT AddGameObject(class GameObject* pGameObject);
		_int Update(_double TimeDelta);
		_int LateUpdate(_double TimeDelta);

	public:
		static Layer* Create();
		virtual void Free() override;

	private:
		list<class GameObject*>			m_Objects;
		typedef list<class GameObject*>	OBJECTS;
	};

}