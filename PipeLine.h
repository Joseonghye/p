#pragma once
#include "Base.h"

namespace Engine
{
	class Camera;
}
//프레임에서 사용되는 뷰, 투영행렬 보관용 
class PipeLine :public Base
{
	DECLARE_SINGLETON(PipeLine)
public:
	enum TRANSFORMSTATEMATRIX { D3DTS_VIEW, D3DTS_PROJECTION, D3DTS_END };
public:
	PipeLine();
	virtual ~PipeLine() = default;

public:
	Camera*		GetMainCamera() { return m_pMainCamera; }
	_fmatrix	GetTransform(TRANSFORMSTATEMATRIX eType) { return XMLoadFloat4x4(&m_TransformMat[eType]); }
	_fvector	GetCamPos() { return XMLoadFloat4(&m_vWorldCamPos); }

	void		SetMainCamera(Camera* cam) { m_pMainCamera = cam; }
	void		SetTransform(TRANSFORMSTATEMATRIX eType, _fmatrix MatTrans) { XMStoreFloat4x4(&m_TransformMat[eType], MatTrans); }

	void		Update();

public:
	virtual void Free() override;

private:
	_float4x4	m_TransformMat[D3DTS_END];
	_float4		m_vWorldCamPos;
	Camera*		m_pMainCamera;
};

