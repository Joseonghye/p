#pragma once

#include "Graphic_Device.h"
#include "TimerMgr.h"
#include "SceneMgr.h"
#include "ObjectMgr.h"
#include "ComponentMgr.h"
#include "PipeLine.h"
#include "Input_Device.h"
#include "LightMgr.h"
#include "FontMgr.h"
#include "SoundManager.h"

namespace Engine
{
	class ENGINE_DLL GameInstance final :public Base
	{
		DECLARE_SINGLETON(GameInstance)

	public:
		explicit			GameInstance();
		virtual				~GameInstance() = default;

	public:
		HRESULT				Initialize_Engine(bool isTool,HINSTANCE hInst, HWND hWnd, _uint iNumScene, Graphic_Device::WINMODE WinMode, _uint iWinCX, _uint iWinCY, ID3D11Device** ppDeviceOut, ID3D11DeviceContext** ppDeviceContextOut);
		_int				Update_Engine(_double TimeDelta);
		HRESULT				Render_Engine();
		HRESULT				Clear_Engine(_uint iSceneIndex);

	public:	// Graphic Device
		HRESULT				Clear_BackBufferView(XMFLOAT4 vClearColor);
		HRESULT				Clear_DepthStencilView();
		HRESULT				Present();

	public: //Input Device
		_byte				Get_DIKeyState(_ubyte byKeyID) const;
		_long				Get_MouseMoveState(Input_Device::MOUSEMOVESTATE eMoveState) const;
		_byte				Get_MouseButtonState(Input_Device::MOUSEBUTTONSTATE eButtonState) const;
		_bool				GetKeyDown(_ubyte key) const;

	public: // TimerMgr
		_double				GetTimeDelta(const _tchar* pTimerTag);
		void				Update_Timer(const _tchar* pTimerTag);
		HRESULT				Ready_Timer(const _tchar* pTimerTag);

	public: // SceneMgr
		HRESULT				OpenScene(_uint iSceneIndex, _uint iNextSceneIndex, class Scene* pOpenScene = nullptr);

	public: // ObjectMgr
		class Component*	GetComponent(_uint iLevelIndex, const _tchar* pLayerTag, const _tchar* pComponentTag, _uint iIndex = 0);
		list<class GameObject*>	GetGameObjectsToLayer(_uint iLevelIndex, const _tchar* pLayerTag);

		HRESULT				AddPrototype(const _tchar* pPrototypeTag, GameObject* pPrototype);
		HRESULT				AddGameObjectToLayer(_uint iSceneIndex, const _tchar* pLayerTag, const _tchar* pPrototypeTag, void* pArg = nullptr, GameObject** pOut = nullptr);

	public: // ComponentMgr
		HRESULT AddPrototype(_uint iSceneIndex, const _tchar* pPrototypeTag, class Component* pPrototype);
		Component* CloneComponent(_uint iSceneIndex, const _tchar* pPrototypeTag, void* pArg);

	public:	// PipeLine
		class Camera* GetMainCamera();
		_fmatrix	GetTransform(PipeLine::TRANSFORMSTATEMATRIX eType);
		_fvector	GetCamPos();

		void		SetMainCamera(class Camera* cam);
		void		SetTransform(PipeLine::TRANSFORMSTATEMATRIX eType, _fmatrix MatTrans);

	public: // LightMgr
		const LIGHTDESC* GetLightDesc(_uint iIndex = 0);
		HRESULT AddLight(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const LIGHTDESC& LightDesc);
		
	public: /* For.Font_Manager */
		HRESULT AddFont(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const _tchar* pFontTag, const _tchar* pFontPath);
		HRESULT Render_Font(const _tchar* pFontTag, XMFLOAT2 vPos, const _tchar* pString, _fvector vColor = Colors::Black);

	public: //m_pSoundMgr
		HRESULT PlaySound(TCHAR* pSoundKey);
		HRESULT PlayBGM(TCHAR* pSoundKey);
		void OnSuspending();
		void OnResuming(); 


	public: 
		static void			Release_Engine();
		virtual void		Free() override;

	private:
		Graphic_Device*		m_pGraphicDevice;
		TimerMgr*			m_pTimerMgr;
		SceneMgr*			m_pSceneMgr;
		ObjectMgr*			m_pObjectMgr;
		ComponentMgr*		m_pComponentMgr;
		PipeLine*			m_pPipeLine;
		Input_Device*		m_pInputDevice;
		LightMgr*			m_pLightMgr;
		FontMgr*			m_pFontMgr;
		SoundManager*		m_pSoundMgr;
	};
}