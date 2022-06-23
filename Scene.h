#pragma once
#include "Base.h"

namespace Engine
{

	class ENGINE_DLL Scene abstract: public Base
	{
	public:
		explicit Scene(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext);
		virtual ~Scene() = default;

	public:
		virtual HRESULT Ready();
		virtual _int	Update(_double TimeDelta);
		virtual HRESULT	Render();

		void SetNextSceneID(_uint iID) { m_iNextSceneID = iID; }

	public:
		virtual	void	Free() override;

	protected:
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;

		_uint					m_iNextSceneID;
	};

}