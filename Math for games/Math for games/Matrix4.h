#pragma once
#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"

class Matrix4
{
public:

	// --- Data definitions ---
	union
	{
		struct
		{
			float x_axis[4];
			float y_axis[4];
			float z_axis[4];
			float w_axis[4];
		};
		struct
		{
			Vector4 right[4];
			Vector4 up[4];
			Vector4 forwards[4];
			Vector4 position[4];
		};
		float _1D[16];
		float _2D[4][4];
		Vector4 axes[4];
	};


	// --- Constructors ---
	Matrix4(const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f, const float a_m03 = 0.0f,	 // Column1
		const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f, const float a_m13 = 0.0f,	 // Column2
		const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f, const float a_m23 = 0.0f,
		const float a_m30 = 0.0f, const float a_m31 = 0.0f, const float a_m32 = 1.0f, const float a_m33 = 0.0f);

	Matrix4(const Vector4& a_right, const Vector4& a_up, const Vector4& a_forwards, const Vector4& a_position);


	// --- Operator overloads ---
	Vector4& operator [] (const int a_index);

	const Vector4& operator [] (const int a_index) const;

	Matrix4 operator * (const Matrix4& a_rhs) const;

	Vector4 operator * (const Vector4& a_rhs) const;

	// NOT FINISHED
	Matrix4& operator *= (const Matrix4& a_rhs);

	Matrix4 operator + (const Matrix4& a_rhs) const;

	Matrix4& operator += (const Matrix4& a_rhs);

	Matrix4 operator - (const Matrix4& a_rhs) const;

	Matrix4& operator -= (const Matrix4& a_rhs);
};

#endif // !MATRIX4_H

