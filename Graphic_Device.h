#pragma once
#include "Base.h"

namespace Engine
{
	class Graphic_Device final : public Base
	{
		DECLARE_SINGLETON(Graphic_Device)

	public:
		enum WINMODE { MODE_FULL, MODE_WIN, MODE_END };
	public:
		Graphic_Device();
		~Graphic_Device() = default;

	public:
		HRESULT Ready_GraphicDevice(HWND hWnd, WINMODE WinMode, _uint iWinCX, _uint iWinCY, ID3D11Device** ppDeviceOut, ID3D11DeviceContext** ppDeviceContextOut);

		HRESULT Clear_BackBufferView(XMFLOAT4 vClearColor);
		HRESULT	Clear_DepthStencilView();

		HRESULT Present();

	private:
		HRESULT Ready_BackBufferRenderTargetView();	//��� ��� ��ü ����� 
		HRESULT Ready_DepthStencilView(_uint iWinCX, _uint iWinCY);
		HRESULT Ready_SwapChain(HWND hWnd, WINMODE eWinMode, _uint iWinCX, _uint iWinCY);

	public:
		virtual void Free() override;

	private:
		ID3D11Device*				m_pDevice; //�޸� �Ҵ�(����)
		ID3D11DeviceContext*		m_pDeviceContext; //���ε��۾� (SetStreamSource,SetIndices)
		IDXGISwapChain*				m_pSwapChain;

		ID3D11RenderTargetView*		m_pBackBufferRTV;
		ID3D11DepthStencilView*		m_pDepthStencilView;
	};

}