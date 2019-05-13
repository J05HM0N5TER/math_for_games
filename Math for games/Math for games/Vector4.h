#pragma once
#ifndef VECTOR4_H
#define VECTOR4_H

#include <cassert>
#include <cmath>

// NOT COMPLETE!!!

template <typename T>
class Vector4
{
public:
	Vector4<T>() {};
	Vector4<T>(const T a_x, const T a_y, const T a_z, const T a_w) : x(a_x), y(a_y), z(a_z), w(a_w) {}

	union
	{
		struct
		{
			T x;
			T y;
			T z;
			T w;
		};
		T data[4];
	};

	/*!
		\brief Subscript operator overload, used for direct access.
		\param a_index [in] The index that the user is trying to access.
	*/
	float& operator[] (const size_t a_index)
	{
		_STL_ASSERT((a_index < 4), "Vector 4 index out of range");
		return data[a_index];
	}

	//! \brief Casting mutable float* operator overloading.
	explicit operator float* ()
	{
		return data;
	}
	//! \brief Casting read only float* operator overloading.
	explicit operator const float* () const
	{
		return data;
	}

	/*!
		\brief Addition operator overloder.
		\param The vector that your plussing to this one.
		\return A vector with the sum of both vectors being added together.
	*/
	Vector4 operator + (const Vector4& a_rhs) const
	{
		return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
	}

	/*!
		\brief Subtraction and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector vector that your subtracting from.
	*/
	Vector4& operator -= (const Vector4& a_rhs)
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		w -= a_rhs.w;
		return *this;
	}

	/*!
		\brief Multiplication operator overloder.
		\param The amount that you are multiplying vector by.
		\return A vector with the completed multiplication.
	*/
	Vector4 operator * (float scalar) const
	{
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	/*!
		\brief Division and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector that your subtracting from.
	*/
	Vector4& operator /= (float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;
		return *this;
	}

	/*!
		\brief Equality operator overloder.
		\param The vector that are copying over the top of the current one.
		\return The pointer to the current vector.
	*/
	Vector4& operator = (const Vector4& a_rhs)
	{
		x = a_rhs.x;
		y = a_rhs.y;
		z = a_rhs.z;
		w = a_rhs.w;
		return *this;
	}

	//! \brief Returns the distance between 0,0,0 and the coordinate.
	T magnitude() const
	{
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(w , 2));
	}

	//! \brief Returns the direction from 0,0,0;
	T normalized() const
	{
		T temp_mag = magnitude();
		return ((x / temp_mag) + (y / temp_mag) + (z / temp_mag) + (w / temp_mag));
	}
};

#endif // !VECTOR4_H

