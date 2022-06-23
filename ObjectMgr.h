#pragma once
#include "Base.h"

namespace Engine
{
	// 객체 원형을 관리
	// 객체 복사본을 씬별로 기준에 따라 나누어 관리
	// 보유한 객체들의 업데이트 호출

	class ObjectMgr final : public Base
	{
		DECLARE_SINGLETON(ObjectMgr)
	private:
		ObjectMgr();
		virtual ~ObjectMgr() = default;

	public:
		class Component* GetComponent(_uint iLevelIndex, const _tchar* pLayerTag, const _tchar* pComponentTag, _uint iIndex);
		list<class GameObject*> GetGameObjectsToLayer(_uint iLevelIndex, const _tchar* pLayerTag);

	public:
		HRESULT ReserveManager(_uint iNumScenes);
		HRESULT AddPrototype(const _tchar* pPrototypeTag, class GameObject* pPrototype);
		HRESULT AddGameObjectToLayer(_uint iSceneIndex, const _tchar* pLayerTag, const _tchar* pPrototypeTag, void* pArg, GameObject** pOut = nullptr);

		_int Update(_double TimeDelta);
		_int LateUpdate(_double TimeDelta);

	public:
		HRESULT ClearLayer(_uint iScenelIndex);

	private:
		GameObject* FindPrototype(const _tchar* pPrototypeTag);
		class Layer* FindLayer(_uint iLevelIndex, const _tchar* pLayerTag);
	public:
		virtual void Free() override;

	private:
		unordered_map<const _tchar*, class GameObject*>	m_Prototype;
		unordered_map<const _tchar*, class Layer*>*		m_pLayers = nullptr;

		typedef unordered_map<const _tchar*, class GameObject*>	PROTOTYPES;
		typedef unordered_map<const _tchar*, class Layer*>			LAYERS;

	private:
		_uint			m_iNumScenes = 0;
	};

}