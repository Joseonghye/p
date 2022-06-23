#include "stdafx.h"
#include "..\public\PersonaUI.h"
#include "GameInstance.h"
#include "UIImage.h"

Client::PersonaUI::PersonaUI()
{
	GameInstance* pGameInstance = GET_INSTANCE(GameInstance);

	GameObject* pOut = nullptr;
	//�丣�ҳ� �������ͽ� ��� �̹��� 
	if (FAILED(pGameInstance->AddGameObjectToLayer(SCENE_STATIC, TEXT("Layer_UI"), TEXT("Prototype_GameObject_Entry"), nullptr, &pOut)))
		return;
	m_pStatusImg = static_cast<UIImage*>(pOut);
	Safe_AddRef(m_pStatusImg);
	m_pStatusImg->SetActive(false);

	//�丣�ҳ� ���� �̸�

	//�丣�ҳ� �̸�

	//�丣�ҳ� ����

	//�丣�ҳ� �Ӽ� 

	//�丣�ҳ� ���� ���� 

	RELEASE_INSTANCE(GameInstance);
}

void Client::PersonaUI::SetVisible(_bool visible)
{
	m_pStatusImg->SetActive(visible);
}

void PersonaUI::Free()
{
	Safe_Release(m_pStatusImg);
}
