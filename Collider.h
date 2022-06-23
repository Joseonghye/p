#pragma once
#include "Component.h"
#include "DebugDraw.h"

namespace Engine
{
	class ENGINE_DLL Collider final: public Component
	{
	public:
		typedef struct tagColliderDesc
		{
			_float3		vScale;
			_float3		vRotation;
			_float3		vPosition;
		} COLLIDERDESC;

	public:
		Collider(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		Collider(const Collider& rhs);
		virtual ~Collider() = default;
	public:
		_vector			GetMin() { return XMLoadFloat4(&m_vMin); }
		_vector			GetMax() { return XMLoadFloat4(&m_vMax); }
	
	public:
		virtual HRESULT Ready_Prototype();
		virtual HRESULT Ready(void* pArg);

		void			Update(_fmatrix TransformMatrix);
		HRESULT			Render();

	public:
		_bool			Collision(Collider* pTarget);

	private:
		_fmatrix		RemoveScale(_fmatrix TransformMatrix);

	public:
		static Collider* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual Component* Clone(void* pArg) override;
		virtual void Free() override;

	private:
		BoundingBox*	m_pCollider;
		BoundingBox*	m_pOrign;

		_float4x4		m_TransformMatrix;
		_float4x4		m_ParentMatrix;

		_bool			m_isCollision;
		_float4			m_vMin;
		_float4			m_vMax;

		_float4			m_vColor;
		BasicEffect*	m_pEffect = nullptr;
		PrimitiveBatch<VertexPositionColor>*		m_pBatch = nullptr;
		ID3D11InputLayout*							m_pInputLayout = nullptr;
	};

}