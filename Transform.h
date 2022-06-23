#pragma once
#include "Component.h"

namespace Engine
{
	//객체의 월드 공간상에서의 상태 (WorldMat)
	// 모든 정점들의 월드 변환
	class ENGINE_DLL Transform final: public Component
	{
	public:
		enum STATE { STATE_RIGHT,STATE_UP,STATE_LOOK,STATE_POSITION,STATE_END };
	public:
		typedef struct tagTransformDesc
		{
			_float	fSpeedPerSec;//초당 이동거리
			_float	fRotationPerSec;
		}TRANSFORMDESC;
	private:
		explicit				Transform(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit				Transform(const Transform& rhs);
		virtual					~Transform() = default;

	public:
		_fvector				GetState(STATE eState) const { return XMLoadFloat4((_float4*)&m_WorldMat.m[eState][0]); }
		_float					GetScale(STATE eState)const { return XMVectorGetX(XMVector3Length(GetState(eState))); }
		_fmatrix				GetWorldMatrix() const { return XMLoadFloat4x4(&m_WorldMat); }
		_fmatrix				GetWorldMatrixInverse() const { return XMMatrixInverse(nullptr,XMLoadFloat4x4(&m_WorldMat)); }

		void					SetState(STATE eState, _fvector vState) { XMStoreFloat4((_float4*)&m_WorldMat.m[eState][0], vState); }
		void					SetTransformDesc(const TRANSFORMDESC& TransDesc) { m_TransformDesc = TransDesc; }	
	
	public:
		virtual HRESULT			Ready_Prototype();
		virtual HRESULT			Ready(void* pArg);

	public:
		void					GoStright(_double TimeDelta); //직진
		void					GoLeft(_double TimeDelta);
		void					GoRight(_double TimeDelta); 
		void					GoBackWard(_double TimeDelta); 

		void					ChaseTarget(const Transform* pTargetTransform,_double TimeDelta);
		void					LookAt(_fvector vTarget);

		void					RotationAxis(_fvector vAxis,_double TimeDelta); //동적으로 회전
		void					RotationAxis(_fvector vAxis, _float fRadian); //동적으로 회전
		void					SetUpRotation(_fvector vAxis, _float fRadian); // 디폴트 상태 기준으로 회전시켜 두는 것

		void					Scaling(_fvector vScale);

	public:
		static Transform*		Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual Component*		Clone(void* pArg) override;
		virtual void			Free() override;

	private:
		_float4x4		m_WorldMat;
		TRANSFORMDESC	m_TransformDesc;
	};

}