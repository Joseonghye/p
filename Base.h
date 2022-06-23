#pragma once
#include "Engine_Define.h"

namespace Engine
{
	class ENGINE_DLL Base abstract
	{
	protected:
		Base();
		virtual ~Base() = default;

	public:
		unsigned long	AddRef();
		unsigned long	Release();

	private:
		unsigned long	m_dwRefCnt = 0;

	public:
		virtual void	Free() = 0;
	};
}