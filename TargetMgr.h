#pragma once
#include "Base.h"

namespace Engine
{
	class TargetMgr final : public Base
	{
		DECLARE_SINGLETON(TargetMgr)
	private:
		TargetMgr();
		virtual ~TargetMgr() = default;

	public:
		ID3D11ShaderResourceView* GetSRV(const _tchar* pTargetTag);

	public:
		HRESULT AddRenderTarget(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext, const _tchar* pTargetTag, _uint iWidth, _uint iHeight, DXGI_FORMAT eFormat, _float4 vClearColor);
		HRESULT AddMRT(const _tchar* pMRTTag, const _tchar* pTargetTag);
		HRESULT BeginMRT(ID3D11DeviceContext* pDeviceContext, const _tchar* pMRTTag); // ������ ����Ÿ�ٵ��� ��ġ�� ������� ���ε� 
		HRESULT EndMRT(ID3D11DeviceContext* pDeviceContext); // ���ε��Ǳ� �������� ����


#ifdef _DEBUG
	public:
		HRESULT Ready_DebugBuffer(const _tchar* pTargetTag, _float fX, _float fY, _float fSizeX, _float fSizeY);
		HRESULT Render_DebugBuffer(const _tchar* pMRTTag);
#endif // _DEBUG

	private:
		typedef map<const _tchar*, class RenderTarget*>	TARGETS;
		TARGETS											m_Targets;

		typedef map<const _tchar*, vector<class RenderTarget*>>	MRTS;
		MRTS													m_MRTs;

	private:
		ID3D11RenderTargetView*				m_pOldView = nullptr;
		ID3D11DepthStencilView*				m_pDepthStencilView = nullptr;

	private:
		class RenderTarget* FindTarget(const _tchar* pTargetTag);
		vector<class RenderTarget*>* FindMRT(const _tchar* pMRTTag);

	public:
		virtual void Free() override;
	};

}