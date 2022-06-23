#pragma once
#include "Client_Define.h"
#include "GameObject.h"

namespace Engine
{
	class Renderer;
	class Model;
	class Transform;
	class HierarchyNode;
	class Collider;
}

namespace Client
{
	class Player final : public GameObject
	{
	protected:
		explicit			Player(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		explicit			Player(const GameObject& rhs);
		virtual				~Player() = default;
	public:
		virtual HRESULT		Ready_Prototype() override;
		virtual HRESULT		Ready(void* pArg) override;

		virtual	_int		Update(_double TimeDelta) override;
		virtual _int		LateUpdate(_double TimeDelta) override;

		virtual HRESULT		Render() override;

	private:
		virtual HRESULT		SetUpComponents();
		HRESULT				SetUpWeapon();
		void				SetState();

	public:
		static Player*		Create(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual GameObject* Clone(void* pArg) override;
		virtual void		Free() override;

	private:
		Renderer*			m_pRenderer; //> �˻��� ���Ѱ� �ƴ�, ���� ����� ���� ����
		Model*				m_pModel;
		Transform*			m_pTransform;
		Collider*			m_pCollider;

		Model*				m_pWeapon;
		HierarchyNode*		m_pWeaponNode;
		_float4x4			m_WeaponMat;

	private:
		STATE				m_eCurState;
		STATE				m_eNextState;
		_bool				m_bBattle;
	};

}