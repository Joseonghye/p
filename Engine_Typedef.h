#ifndef __Engine_Typedef_h__
#define __Engine_Typedef_h__

namespace Engine
{
	typedef		bool				_bool;

	typedef		signed char			_byte;
	typedef		unsigned char		_ubyte;

	typedef		wchar_t				_tchar;

	typedef		signed short		_short;
	typedef		unsigned short		_ushort;

	typedef		signed int			_int;
	typedef		unsigned int		_uint;

	typedef		signed long			_long;
	typedef		unsigned long		_ulong;

	typedef		float				_float;
	typedef		double				_double;

	typedef		XMFLOAT2			_float2;
	typedef		XMFLOAT3			_float3;
	typedef		XMFLOAT4			_float4;

	typedef		XMVECTOR			_vector;

	//SIMD 좀더빠른 연산을 위해 고안된 연산법 
	//지역변수로만 할당가능STACK 메모리에만 (멤버로 할당된 순간 SIMD 연산 불가능)
	typedef		XMVECTOR			_vector;
	typedef		FXMVECTOR			_fvector;
	typedef		GXMVECTOR			_gvector;

	typedef		XMFLOAT4X4			_float4x4;
	typedef		XMMATRIX			_matrix;
	typedef		FXMMATRIX			_fmatrix;
	typedef		CXMMATRIX			_cmatrix;

#define VEC_ZERO	XMVectorSet(0.f,0.f,0.f,0.f)
#define VEC_ONE		XMVectorSet(1.f,1.f,1.f,0.f)
#define VEC_RIGHT	XMVectorSet(1.f,0.f,0.f,0.f)
#define VEC_UP		XMVectorSet(0.f,1.f,0.f,0.f)
#define VEC_LOOK	XMVectorSet(0.f,0.f,1.f,0.f)

	enum GameObjectTag
	{
		DEFAULT,
		PLAYER,
		MONSTER,
		OBJECT,
		EFFECT,
		UI,
		CAMERA,
		END
	};

}

#endif // !__Engine_Typedef_h__
