#include "../public/PipeLine.h"

IMPLEMENT_SINGLETON(PipeLine)

PipeLine::PipeLine()
{
}

void PipeLine::Update()
{
	//ī�޶� ��ġ ���
	_matrix camWorldMat = XMMatrixInverse(nullptr, XMLoadFloat4x4(&m_TransformMat[D3DTS_VIEW]));

	XMStoreFloat4(&m_vWorldCamPos, camWorldMat.r[3]);
}

void PipeLine::Free()
{
}
