#pragma once

#include "Base.h"

namespace Engine{

class Input_Device final : public Base
{
	DECLARE_SINGLETON(Input_Device)
public:
	enum MOUSEMOVESTATE { MMS_X, MMS_Y, MMS_WHEEL, MMS_END };
	enum MOUSEBUTTONSTATE { MBS_LBUTTON, MBS_RBUTTON, MBS_WHEEL, MBS_END };
	enum KeyState { UP, DOWN, PRESS };
private:
	Input_Device();
	virtual ~Input_Device() = default;
public:
	_byte Get_DIKeyState(_ubyte byKeyID) const {
		return m_KeyBoardState[byKeyID];
	}

	_long Get_MouseMoveState(MOUSEMOVESTATE eMoveState) const {
		return ((_long*)&m_MouseState)[eMoveState];
	}

	_byte Get_MouseButtonState(MOUSEBUTTONSTATE eButtonState) const {
		return m_MouseState.rgbButtons[eButtonState];
	}
	
public:
	HRESULT Ready_Input_Device(HINSTANCE hInst, HWND hWnd);
	
	/* 입력장치의 현재 상태를 얻어온다. */
	HRESULT SetUp_InputDeviceState();

public:
	_bool	GetKeyDown(_ubyte key);

private:
	IDirectInput8*			m_pInputSDK = nullptr;
	IDirectInputDevice8*	m_pKeyBoard = nullptr;
	IDirectInputDevice8*	m_pMouse = nullptr;

private:	
	_byte				m_KeyBoardState[256] = {};
	KeyState			m_eKeyState[256] = {};
	DIMOUSESTATE		m_MouseState;
public:
	virtual void Free() override;
};

}