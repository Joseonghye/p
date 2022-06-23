#pragma once
#include "Base.h"

namespace Engine 
{
	class Animation : public Base
	{
	public:
		Animation();
		virtual ~Animation() = default;

	public:
		_bool	GetCurrentAnimtaionEnd() { return m_isFinished; }
		void	Reset();
	public:
		HRESULT	Ready(char* pName, _double Duration, _double PlaySpeed);
		HRESULT UpdateTransformationMatrix(_double TimeDelta);

		HRESULT AddChannel(class AnimChannel* pChannel);
	public:
		static Animation* Create(char* pName, _double Duration, _double PlaySpeed);
		virtual void Free() override;

	private:
		char		m_szName[MAX_PATH];
		_bool		m_isFinished;
		_double		m_Duration; //재생시간
		_double		m_TrackPositionAcc;
		_double		m_PlaySpeed;

	private:	//애니메이션에 영향을 주는 뼈대 정보 
		vector<class AnimChannel*>	m_Channels;
		typedef vector<class AnimChannel*> CHANNELS;
	};

}