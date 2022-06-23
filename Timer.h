#pragma once
#include "Base.h"

namespace Engine
{
class ENGINE_DLL Timer : public Base
{
private:
							Timer();
	virtual					~Timer() = default;

public:
	_double					GetTimeDelta(void) const { return m_fTimeDelta; }

public:
	HRESULT					Ready(void);
	void					Update(void);

private:
	LARGE_INTEGER			m_FrameTime;
	LARGE_INTEGER			m_FixTime;
	LARGE_INTEGER			m_LastTime;
	LARGE_INTEGER			m_CpuTick;

private:
	_double					m_fTimeDelta;

public:
	static Timer* Create(void);
	virtual void Free(void) override;
};

}