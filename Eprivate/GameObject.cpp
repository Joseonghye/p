#include "..\public\GameObject.h"
#include "GameInstance.h"
#include "Component.h"

Engine::GameObject::GameObject(ID3D11Device * pDevice, ID3D11DeviceContext * pDeviceContext)
	:m_pDevice(pDevice), m_pDeviceContext(pDeviceContext),
	m_eTag(GameObjectTag::DEFAULT), m_strName("")
{
	Safe_AddRef(m_pDeviceContext);
	Safe_AddRef(m_pDevice);
}

Engine::GameObject::GameObject(const GameObject & rhs)
	: m_pDevice(rhs.m_pDevice), m_pDeviceContext(rhs.m_pDeviceContext)
{
	Safe_AddRef(m_pDeviceContext);
	Safe_AddRef(m_pDevice);
}

Component * Engine::GameObject::GetComponent(const _tchar * pComponentTag)
{
	auto	iter = find_if(m_Components.begin(), m_Components.end(), Tag_Finder(pComponentTag));

	if (iter == m_Components.end())
		return nullptr;

	return iter->second;
}

HRESULT Engine::GameObject::Ready_Prototype()
{
	return S_OK;
}

HRESULT Engine::GameObject::Ready(void * pArg)
{
	return S_OK;
}

_int Engine::GameObject::Update(_double TimeDelta)
{
	return _int();
}

_int Engine::GameObject::LateUpdate(_double TimeDelta)
{
	return _int();
}

HRESULT Engine::GameObject::Render()
{
	return S_OK;
}

HRESULT Engine::GameObject::SetUpComponents(_uint iSceneIndex, const _tchar * pPrototypeTag, const _tchar * pComponentTag, Component ** ppOut, void * pArg)
{
	// pPrototypeTag : ������ü�� ã�� ���� �̸�
	// pComponentTag : ������ �� �̸� 

	auto	iter = find_if(m_Components.begin(), m_Components.end(), Tag_Finder(pComponentTag));

	if (iter != m_Components.end())
		return E_FAIL;

	GameInstance*		pGameInstance = GET_INSTANCE(GameInstance);

	Component*		pComponent = pGameInstance->CloneComponent(iSceneIndex, pPrototypeTag, pArg);
	if (nullptr == pComponent)
		return E_FAIL;

	pComponent->SetOwner(this);

	//map�� ����
	m_Components.emplace(pComponentTag, pComponent);
	//�ڽĿ��Ե� ������ ���� out
	*ppOut = pComponent;

	Safe_AddRef(pComponent);

	RELEASE_INSTANCE(GameInstance);

	return S_OK;
}

//HRESULT Engine::GameObject::SetUpComponents(_uint iSceneIndex, const _tchar * pPrototypeTag, Component ** ppOut, void * pArg)
//{
//	/*auto	iter = find_if(m_Components.begin(), m_Components.end(), Tag_Finder(pComponentTag));
//
//	if (iter != m_Components.end())
//		return E_FAIL;*/
//
//	GameInstance*		pGameInstance = GET_INSTANCE(GameInstance);
//
//	Component*		pComponent = pGameInstance->CloneComponent(iSceneIndex, pPrototypeTag, pArg);
//	if (nullptr == pComponent)
//		return E_FAIL;
//
//	//map�� ����
//	m_Components.push_back(pComponent);
//	//�ڽĿ��Ե� ������ ���� out
//	*ppOut = pComponent;
//
//	Safe_AddRef(pComponent);
//
//	RELEASE_INSTANCE(GameInstance);
//
//	return S_OK;
//}

void Engine::GameObject::Free()
{
	for (auto& Pair : m_Components)
		Safe_Release(Pair.second);
	//	Safe_Release(Pair);
		//	

	m_Components.clear();

	Safe_Release(m_pDeviceContext);
	Safe_Release(m_pDevice);
}
