#pragma once
#include "Base.h"

namespace Engine 
{
	//애니메이션에 사용되는 뼈 
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

	private:// 현재 뼈가 표현해야할  키프레임에 따른 상태행렬(스케일/회전/이동) 보관
		vector<KEYFRAME*> m_KeyFrames;
		typedef vector<KEYFRAME*> KEYFRAMES;

	};

}