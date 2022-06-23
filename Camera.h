#pragma once

#include "GameObject.h"
#include "Transform.h"
#include "PipeLine.h"

namespace Engine {

	class ENGINE_DLL Camera abstract :public GameObject
	{
	public:
		typedef struct tagCameraDesc
		{
			_float3 vEye,vAt,vAxisY;
			_float  fAspect, fFovy, fNear, fFar;

			Transform::TRANSFORMDESC TransformDesc;
		}CAMERADESC;
	public:
		explicit Camera(ID3D11Device* pDevice,ID3D11DeviceContext* pDeviceContext);
		explicit Camera(const Camera& rhs);
		virtual ~Camera() = default;

	public:
		_fvector GetForward() { return m_pTransform->GetState(Transform::STATE_LOOK); }
	public:
		virtual HRESULT Ready_Prototype();
		virtual HRESULT Ready(void* pArg);
		virtual _int	Update(_double TimeDelta);
		virtual _int	LateUpdate(_double TimeDelta);
		virtual HRESULT Render();

	public:
		virtual GameObject* Clone(void* pArg) = 0;
		virtual void Free() override;

	protected:
		class Transform*	m_pTransform;
		CAMERADESC			m_CameraDesc;
	};

}