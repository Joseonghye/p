#pragma once
#include "Base.h"

namespace Engine 
{
	//�ִϸ��̼ǿ� ���Ǵ� �� 
	class AnimChannel :public Base
	{
	public:
		AnimChannel();
		virtual ~AnimChannel() = default;

	public:
		void SetCurKeyFrameIndex(_uint index) { m_iCurKeyFrameIndex = index; }

		vector<KEYFRAME*> GetKeyFrames() { return m_KeyFrames; }
		_uint GetCurKeyFrameIndex() { return m_iCurKeyFrameIndex; }
		_matrix GetTransformMatrix() const { return XMLoadFloat4x4(&m_TransformationMatrix); }

		void SetTransformMatrix(_fmatrix TransformationMatrix) {
		XMStoreFloat4x4(&m_TransformationMatrix, TransformationMatrix);
	}
	public:
		HRESULT Ready(const char* pName);
		void UpdateTransformationMatrix(_double TrackPositionAcc);

		HRESULT ReserveKeyFrames(_uint size);
		HRESULT AddKeyFrame(KEYFRAME* pKeyFrame);

	public:
		static AnimChannel* Create(const char* pName);
		virtual void Free() override;

	private:
		char			m_szName[MAX_PATH];
		_uint			m_iCurKeyFrameIndex;
		_float4x4		m_TransformationMatrix;

	private:// ���� ���� ǥ���ؾ���  Ű�����ӿ� ���� �������(������/ȸ��/�̵�) ����
		vector<KEYFRAME*> m_KeyFrames;
		typedef vector<KEYFRAME*> KEYFRAMES;

	};

}