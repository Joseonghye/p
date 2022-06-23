#include "..\public\Base.h"

Base::Base()
	:m_dwRefCnt(0)
{
}

unsigned long Base::AddRef()
{
	return ++m_dwRefCnt;
}

unsigned long Base::Release()
{
	//�������� ���ϸ� ����
	if (0 == m_dwRefCnt)
	{
		Free();
		delete this;
		return 0;
	}
	else
		return m_dwRefCnt--;
}