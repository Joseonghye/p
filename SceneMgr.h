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
		HRESULT			OpenScene(_uint iSceneID, _uint iNextID,class Scene* pOpenScene = nullptr); // ���� ������ ���ְ� �����ְ� ���� ���� ����
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