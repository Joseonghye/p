#pragma once
#include "Base.h"

namespace Engine
{
	class SceneMgr final : public Base
	{
		DECLARE_SINGLETON(SceneMgr)

	public:
		explicit		SceneMgr();
		virtual			~SceneMgr() = default;

	public:
		HRESULT			OpenScene(_uint iSceneID, _uint iNextID,class Scene* pOpenScene = nullptr); // 기존 레벨을 없애고 보여주고 싶은 레벨 셋팅
		_int			Update(_double TimeDelta);
		HRESULT			Render();

	private:
		HRESULT			Clear();

	public:
		virtual void	Free() override;

	private:
		_uint			m_iCurrentSceneID;
		//vector<class Scene*>	m_pScenes;
		class Scene*	m_pCurScene;
	};

}