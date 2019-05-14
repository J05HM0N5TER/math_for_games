#include "Matrix3.h"



Matrix3::Matrix3(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/,	 // Column1
			     const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/,	 // Column2
				 const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/) : // Column3
	_1D{a_m00, a_m01, a_m02, a_m10, a_m11, a_m12, a_m20, a_m21, a_m22}
{
}

Matrix3::Matrix3(const Vector3& a_right, const Vector3& a_up, const Vector3& a_forwards) :
	axes{ a_right , a_up , a_forwards }
{}

Vector3 & Matrix3::operator[](const int a_index)
{
	return axes[a_index];
}

const Vector3 & Matrix3::operator[](const int a_index) const
{
	return axes[a_index];
}

Matrix3 Matrix3::operator*(const Matrix3& a_rhs) const
{
	return 
	{
		_2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2], // First line
		_2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2], // Expand to 1 column
		_2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2], // 33%

		_2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2], // Moving accress RHS columns
		_2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2],
		_2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2], // 66%

		_2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2], // Moving accress RHS columns
		_2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2],
		_2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2], // 100%
	};
}

Matrix3 Matrix3::operator*=(const Matrix3 & a_rhs)
{
	_2D[0][0] = (_2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2]); // First line
	_2D[0][1] = (_2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2]); // Expand to 1 column
	_2D[0][2] = (_2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2]); // 33%

	_2D[1][0] = (_2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2]); // Moving accress RHS columns
	_2D[1][1] = (_2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2]);
	_2D[1][2] = (_2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2]); // 66%

	_2D[2][0] = (_2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2]); // Moving accress RHS columns
	_2D[2][1] = (_2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2]);
	_2D[2][2] = (_2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2]);

	return *this;
}

Matrix3 Matrix3::operator+(const Matrix3 & a_rhs) const
{
	return
	{
		_2D[0][0] + a_rhs._2D[0][0], _2D[0][1] + a_rhs._2D[0][1], _2D[0][2] + a_rhs._2D[0][2],
		_2D[1][0] + a_rhs._2D[1][0], _2D[1][1] + a_rhs._2D[1][1], _2D[1][2] + a_rhs._2D[1][2],
		_2D[2][0] + a_rhs._2D[2][0], _2D[2][1] + a_rhs._2D[2][1], _2D[2][2] + a_rhs._2D[2][2]
	};
}

Matrix3 & Matrix3::operator+=(const Matrix3 & a_rhs)
{
	_2D[0][0] += a_rhs._2D[0][0];
	_2D[0][1] += a_rhs._2D[0][1];
	_2D[0][2] += a_rhs._2D[0][2];

	_2D[1][0] += a_rhs._2D[1][0];
	_2D[1][1] += a_rhs._2D[1][1];
	_2D[1][2] += a_rhs._2D[1][2];

	_2D[2][0] += a_rhs._2D[2][0];
	_2D[2][1] += a_rhs._2D[2][1];
	_2D[2][2] += a_rhs._2D[2][2];

	return *this;
}

Matrix3 Matrix3::operator-(const Matrix3 & a_rhs) const
{
	return
	{
		_2D[0][0] - a_rhs._2D[0][0], _2D[0][1] - a_rhs._2D[0][1], _2D[0][2] - a_rhs._2D[0][2],
		_2D[1][0] - a_rhs._2D[1][0], _2D[1][1] - a_rhs._2D[1][1], _2D[1][2] - a_rhs._2D[1][2],
		_2D[2][0] - a_rhs._2D[2][0], _2D[2][1] - a_rhs._2D[2][1], _2D[2][2] - a_rhs._2D[2][2]
	};
}

Matrix3 & Matrix3::operator-=(const Matrix3 & a_rhs)
{
	_2D[0][0] -= a_rhs._2D[0][0];
	_2D[0][1] -= a_rhs._2D[0][1];
	_2D[0][2] -= a_rhs._2D[0][2];

	_2D[1][0] -= a_rhs._2D[1][0];
	_2D[1][1] -= a_rhs._2D[1][1];
	_2D[1][2] -= a_rhs._2D[1][2];

	_2D[2][0] -= a_rhs._2D[2][0];
	_2D[2][1] -= a_rhs._2D[2][1];
	_2D[2][2] -= a_rhs._2D[2][2];

	return *this;
}