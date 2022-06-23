#pragma once
#include "Base.h"

namespace Engine
{
	class TimerMgr : public Base
	{
		DECLARE_SINGLETON(TimerMgr)

	private:
							TimerMgr();
		virtual				~TimerMgr() = default;

	public:
		_double				GetTimeDelta(const _tchar* pTimerTag);

	public:
		HRESULT				Ready_Timer(const _tchar* pTimerTag);
		void				Update_Timer(const _tchar* pTimerTag);

	private:
		class Timer*		Find_Timer(const _tchar* pTimerTag);

	private:
		map<const _tchar*, class Timer*>			m_mapTimer;

	public:
		virtual void		Free();
	};

}