#include "Matrix4.h"


Matrix4::Matrix4(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/, const float a_m03 /*= 0.0f*/,	 // Column1
			 	 const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/, const float a_m13 /*= 0.0f*/,	 // Column2
				 const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/, const float a_m23 /*= 0.0f*/,
				 const float a_m30 /*= 0.0f*/, const float a_m31 /*= 0.0f*/, const float a_m32 /*= 1.0f*/, const float a_m33 /*= 0.0f*/) : // Column3
	_1D{ a_m00, a_m01, a_m02, a_m03, a_m10, a_m11, a_m12, a_m13, a_m20, a_m21, a_m22, a_m23, a_m30, a_m31, a_m32, a_m33 }
{
}

Matrix4::Matrix4(const Vector4& a_right, const Vector4& a_up, const Vector4& a_forwards, const Vector4& a_position) :
	axes{ a_right , a_up , a_forwards, a_position}
{}

Matrix4::operator float*()
{
	return _1D;
}

Matrix4::operator const float*() const
{
	return _1D;
}

Vector4 & Matrix4::operator[](const int a_index)
{
	return axes[a_index];
}

const Vector4 & Matrix4::operator[](const int a_index) const
{
	return axes[a_index];
}

Matrix4 Matrix4::operator*(const Matrix4& a_rhs) const
{
	return
	{
		_2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2] + _2D[3][0] * a_rhs._2D[0][2],
		_2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2] + _2D[3][1] * a_rhs._2D[0][2],
		_2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2] + _2D[3][2] * a_rhs._2D[0][2],
		_2D[0][3] * a_rhs._2D[0][0] + _2D[1][3] * a_rhs._2D[0][1] + _2D[2][3] * a_rhs._2D[0][2] + _2D[3][3] * a_rhs._2D[0][2],

		_2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2] + _2D[3][0] * a_rhs._2D[1][2], 
		_2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2] + _2D[3][1] * a_rhs._2D[1][2], 
		_2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2] + _2D[3][2] * a_rhs._2D[1][2],
		_2D[0][3] * a_rhs._2D[1][0] + _2D[1][3] * a_rhs._2D[1][1] + _2D[2][3] * a_rhs._2D[1][2] + _2D[3][3] * a_rhs._2D[1][2],
																								  
		_2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2] + _2D[3][0] * a_rhs._2D[2][2], 
		_2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2] + _2D[3][1] * a_rhs._2D[2][2], 
		_2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2] + _2D[3][2] * a_rhs._2D[2][2],
		_2D[0][3] * a_rhs._2D[2][0] + _2D[1][3] * a_rhs._2D[2][1] + _2D[2][3] * a_rhs._2D[2][2] + _2D[3][3] * a_rhs._2D[2][2],
																								  
		_2D[0][0] * a_rhs._2D[3][0] + _2D[1][0] * a_rhs._2D[3][1] + _2D[2][0] * a_rhs._2D[3][2] + _2D[3][0] * a_rhs._2D[3][2], 
		_2D[0][1] * a_rhs._2D[3][0] + _2D[1][1] * a_rhs._2D[3][1] + _2D[2][1] * a_rhs._2D[3][2] + _2D[3][1] * a_rhs._2D[3][2], 
		_2D[0][2] * a_rhs._2D[3][0] + _2D[1][2] * a_rhs._2D[3][1] + _2D[2][2] * a_rhs._2D[3][2] + _2D[3][2] * a_rhs._2D[3][2],
		_2D[0][3] * a_rhs._2D[3][0] + _2D[1][3] * a_rhs._2D[3][1] + _2D[2][3] * a_rhs._2D[3][2] + _2D[3][3] * a_rhs._2D[3][2]
	};


}

Vector4 Matrix4::operator*(const Vector4 & a_rhs) const
{
	return
	{
		_2D[0][0] * a_rhs[0] + _2D[1][0] * a_rhs[1] + _2D[2][0] * a_rhs[2] + _2D[3][0] * a_rhs[3],
		_2D[0][1] * a_rhs[0] + _2D[1][1] * a_rhs[1] + _2D[2][1] * a_rhs[2] + _2D[3][0] * a_rhs[3],
		_2D[0][2] * a_rhs[0] + _2D[1][2] * a_rhs[1] + _2D[2][2] * a_rhs[2] + _2D[3][0] * a_rhs[3],
		_2D[0][3] * a_rhs[0] + _2D[1][3] * a_rhs[1] + _2D[2][3] * a_rhs[2] + _2D[3][0] * a_rhs[3]
	};
}

Matrix4& Matrix4::operator*=(const Matrix4 & a_rhs)
{
	float temp[3][3];

	temp[0][0] = _2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2] + _2D[3][0] * a_rhs._2D[0][2];
	temp[0][1] = _2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2] + _2D[3][1] * a_rhs._2D[0][2];
	temp[0][2] = _2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2] + _2D[3][2] * a_rhs._2D[0][2];
	temp[0][3] = _2D[0][3] * a_rhs._2D[0][0] + _2D[1][3] * a_rhs._2D[0][1] + _2D[2][3] * a_rhs._2D[0][2] + _2D[3][3] * a_rhs._2D[0][2];

	temp[1][0] = _2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2] + _2D[3][0] * a_rhs._2D[1][2];
	temp[1][1] = _2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2] + _2D[3][1] * a_rhs._2D[1][2];
	temp[1][2] = _2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2] + _2D[3][2] * a_rhs._2D[1][2];
	temp[1][3] = _2D[0][3] * a_rhs._2D[1][0] + _2D[1][3] * a_rhs._2D[1][1] + _2D[2][3] * a_rhs._2D[1][2] + _2D[3][3] * a_rhs._2D[1][2];

	temp[2][0] = _2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2] + _2D[3][0] * a_rhs._2D[2][2];
	temp[2][1] = _2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2] + _2D[3][1] * a_rhs._2D[2][2];
	temp[2][2] = _2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2] + _2D[3][2] * a_rhs._2D[2][2];
	temp[2][3] = _2D[0][3] * a_rhs._2D[2][0] + _2D[1][3] * a_rhs._2D[2][1] + _2D[2][3] * a_rhs._2D[2][2] + _2D[3][3] * a_rhs._2D[2][2];

	temp[3][0] = _2D[0][0] * a_rhs._2D[3][0] + _2D[1][0] * a_rhs._2D[3][1] + _2D[2][0] * a_rhs._2D[3][2] + _2D[3][0] * a_rhs._2D[3][2];
	temp[3][1] = _2D[0][1] * a_rhs._2D[3][0] + _2D[1][1] * a_rhs._2D[3][1] + _2D[2][1] * a_rhs._2D[3][2] + _2D[3][1] * a_rhs._2D[3][2];
	temp[3][2] = _2D[0][2] * a_rhs._2D[3][0] + _2D[1][2] * a_rhs._2D[3][1] + _2D[2][2] * a_rhs._2D[3][2] + _2D[3][2] * a_rhs._2D[3][2];
	temp[3][3] = _2D[0][3] * a_rhs._2D[3][0] + _2D[1][3] * a_rhs._2D[3][1] + _2D[2][3] * a_rhs._2D[3][2] + _2D[3][3] * a_rhs._2D[3][2];


	_2D[0][0] = temp[0][0];
	_2D[0][1] = temp[0][1];
	_2D[0][2] = temp[0][2];
	_2D[0][3] = temp[0][3];

	_2D[1][0] = temp[1][0];
	_2D[1][1] = temp[1][1];
	_2D[1][2] = temp[1][2];
	_2D[1][3] = temp[1][3];

	_2D[2][0] = temp[2][0];
	_2D[2][1] = temp[2][1];
	_2D[2][2] = temp[2][2];
	_2D[2][3] = temp[2][3];
		
	_2D[3][0] = temp[3][0];
	_2D[3][1] = temp[3][1];
	_2D[3][2] = temp[3][2];
	_2D[3][3] = temp[3][3];

	return *this;
}

Matrix4 Matrix4::operator+(const Matrix4 & a_rhs) const
{
	return
	{
		_2D[0][0] + a_rhs._2D[0][0], _2D[0][1] + a_rhs._2D[0][1], _2D[0][2] + a_rhs._2D[0][2], _2D[0][3] + a_rhs._2D[0][3],
		_2D[1][0] + a_rhs._2D[1][0], _2D[1][1] + a_rhs._2D[1][1], _2D[1][2] + a_rhs._2D[1][2], _2D[1][3] + a_rhs._2D[1][3],
		_2D[2][0] + a_rhs._2D[2][0], _2D[2][1] + a_rhs._2D[2][1], _2D[2][2] + a_rhs._2D[2][2], _2D[2][3] + a_rhs._2D[2][3],
		_2D[3][0] + a_rhs._2D[3][0], _2D[3][1] + a_rhs._2D[3][1], _2D[3][2] + a_rhs._2D[3][2], _2D[3][3] + a_rhs._2D[3][3]
	};
}

Matrix4 & Matrix4::operator+=(const Matrix4 & a_rhs)
{
	_2D[0][0] += a_rhs._2D[0][0];
	_2D[0][1] += a_rhs._2D[0][1];
	_2D[0][2] += a_rhs._2D[0][2];
	_2D[0][3] += a_rhs._2D[0][3];

	_2D[1][0] += a_rhs._2D[1][0];
	_2D[1][1] += a_rhs._2D[1][1];
	_2D[1][2] += a_rhs._2D[1][2];
	_2D[1][3] += a_rhs._2D[1][3];

	_2D[2][0] += a_rhs._2D[2][0];
	_2D[2][1] += a_rhs._2D[2][1];
	_2D[2][2] += a_rhs._2D[2][2];
	_2D[2][3] += a_rhs._2D[2][3];

	_2D[3][0] += a_rhs._2D[3][0];
	_2D[3][1] += a_rhs._2D[3][1];
	_2D[3][2] += a_rhs._2D[3][2];
	_2D[3][3] += a_rhs._2D[3][3];

	return *this;
}

Matrix4 Matrix4::operator-(const Matrix4 & a_rhs) const
{
	return
	{
		_2D[0][0] - a_rhs._2D[0][0], _2D[0][1] - a_rhs._2D[0][1], _2D[0][2] - a_rhs._2D[0][2], _2D[0][3] - a_rhs._2D[0][3],
		_2D[1][0] - a_rhs._2D[1][0], _2D[1][1] - a_rhs._2D[1][1], _2D[1][2] - a_rhs._2D[1][2], _2D[1][3] - a_rhs._2D[1][3],
		_2D[2][0] - a_rhs._2D[2][0], _2D[2][1] - a_rhs._2D[2][1], _2D[2][2] - a_rhs._2D[2][2], _2D[2][3] - a_rhs._2D[2][3],
		_2D[3][0] - a_rhs._2D[3][0], _2D[3][1] - a_rhs._2D[3][1], _2D[3][2] - a_rhs._2D[3][2], _2D[3][3] - a_rhs._2D[3][3]
	};
}

Matrix4 & Matrix4::operator-=(const Matrix4 & a_rhs)
{
	_2D[0][0] -= a_rhs._2D[0][0];
	_2D[0][1] -= a_rhs._2D[0][1];
	_2D[0][2] -= a_rhs._2D[0][2];
	_2D[0][3] -= a_rhs._2D[0][3];

	_2D[1][0] -= a_rhs._2D[1][0];
	_2D[1][1] -= a_rhs._2D[1][1];
	_2D[1][2] -= a_rhs._2D[1][2];
	_2D[1][3] -= a_rhs._2D[1][3];

	_2D[2][0] -= a_rhs._2D[2][0];
	_2D[2][1] -= a_rhs._2D[2][1];
	_2D[2][2] -= a_rhs._2D[2][2];
	_2D[2][3] -= a_rhs._2D[2][3];

	_2D[3][0] -= a_rhs._2D[3][0];
	_2D[3][1] -= a_rhs._2D[3][1];
	_2D[3][2] -= a_rhs._2D[3][2];
	_2D[3][3] -= a_rhs._2D[3][3];

	return *this;
}
