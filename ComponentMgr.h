#pragma once
#include "Base.h"

#include "Renderer.h"
#include "RectBuffer.h"
#include "TerrainBuffer.h"
#include "CubeBuffer.h"
#include "Texture.h"
#include "Model.h"
#include "Transform.h"
#include "Collider.h"

namespace Engine
{
	class ComponentMgr final : public Base
	{
		DECLARE_SINGLETON(ComponentMgr)
	private:
		ComponentMgr();
		virtual ~ComponentMgr() = default;

	public:
		HRESULT ReserveManager(_uint iNumScenes);
		HRESULT AddPrototype(_uint iSceneIndex, const _tchar* pPrototypeTag, class Component* pPrototype);
		Component* CloneComponent(_uint iSceneIndex, const _tchar* pPrototypeTag, void* pArg);

	private:
		Component* FindPrototypeComponent(_uint iSceneIndex, const _tchar* pComponentTag);

	public:
		virtual void Free() override;

	private:
		unordered_map<const _tchar*, class Component*>*			m_pComponents = nullptr;
		typedef unordered_map<const _tchar*, class Component*>		COMPONENTS;
	
		_uint			m_iNumScene = 0;
	};

}