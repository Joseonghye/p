#ifndef __Engine_Function_h__
#define __Engine_Function_h__

namespace Engine
{
	//템플릿은 기능은 정해져있으나 자료형은 정해져 있지 않은 것.
	//기능을 인스턴스화 하기 위해 만들어두는 '틀'

	template<typename T>
	void Safe_Delete(T& Pointer)
	{
		if (nullptr != Pointer)
		{
			delete Pointer;
			Pointer = nullptr;
		}
	}

	template<typename T>
	void Safe_Delete_Array(T& Pointer)
	{
		if (nullptr != Pointer)
		{
			delete[] Pointer;
			Pointer = nullptr;
		}
	}

	template<typename T>
	unsigned long Safe_AddRef(T& pInstance)
	{
		unsigned long dwRefCnt = 0;

		if (nullptr != pInstance)
			dwRefCnt = pInstance->AddRef();

		return dwRefCnt;
	}

	template<typename T>
	unsigned long Safe_Release(T& pInstance)
	{
		unsigned long dwRefCnt = 0;

		if (nullptr != pInstance)
		{
			dwRefCnt = pInstance->Release();

			if (0 == dwRefCnt)
				pInstance = nullptr;
		}

		return dwRefCnt;
	}


	class Tag_Finder
	{
	public:
		explicit Tag_Finder(const wchar_t* pTag) : m_pTargetTag(pTag) {}
		~Tag_Finder(void) {}

	public:
		template<typename T>
		bool		operator()(const T& pair)
		{
			if (0 == lstrcmpW(m_pTargetTag, pair.first))
				return true;

			return false;
		}

	private:
		const wchar_t*		m_pTargetTag = nullptr;
	};
}

#endif // !__Engine_Function_h__

