#pragma once
#include "Base.h"

namespace Engine
{
	class SoundManager :public Base
	{
		DECLARE_SINGLETON(SoundManager)

	private:
		SoundManager();
		virtual ~SoundManager() = default;

	public:
		HRESULT Ready_SoundMgr();
		_int Update_SoundMgr();

	public:
		void OnSuspending(); //종료
		void OnResuming(); //재개 

		void PlaySound(_tchar* pSoundKey);
		void PlayBGM(TCHAR* pSoundKey);

	private:
		HRESULT LoadSoundFile();
		

	public:
		virtual void Free();

	private:
		DirectX::AudioEngine* m_pAudioEngine;
		map<_tchar*, DirectX::SoundEffect*> m_mapSound;
		unique_ptr<DirectX::SoundEffectInstance> m_pBGM;

		_bool m_bStart = false;
		_bool m_bEnd = false;
		_bool m_bRealEnd = false;
		_float m_Time;
		_float m_fVolume = 0.f;

	};

}