#pragma once
#ifndef VECTOR2_H
#define VECTOR_2

#include <cassert>
#include <cmath>

template <typename T>
class Vector2
{
public:
	Vector2<T>() {};
	Vector2<T>(const T a_x, const T a_y) : x(a_x), y(a_y) {}

	union
	{
		struct
		{
			T x;
			T y;
		};
		T data[2];
	};

	/*!
		\brief Subscript operator overload, used for direct access.
		\param a_index [in] The index that the user is trying to access.
	*/
	T& operator[] (const size_t a_index)
	{
		_STL_ASSERT((a_index < 2), "Vector 2 index out of range");
		return data[a_index];
	}

	//! \brief Casting mutable float* operator overloading.
	explicit operator T* ()
	{
		return data;
	}
	//! \brief Casting read only float* operator overloading.
	explicit operator const T* () const
	{
		return data;
	}

	/*!
		\brief Addition operator overload.
		\param The vector that your plussing to this one.
		\return A vector with the sum of both vectors being added together.
	*/
	Vector2<T> operator + (const Vector2<T>& a_rhs) const
	{
		return Vector2<T>(x + a_rhs.x, y + a_rhs.y);
	}

	/*!
		\brief Addition and equality overload.
		\param a_rhs [in] The vector that is being added.
		\return The pointer to the current vector.
	*/
	Vector2<T>& operator += (const Vector2<T> a_rhs)
	{
		x += a_rhs.x;
		y += a_rhs.y;
		return *this;
	}

	/*!
		\brief Subtraction operator overload.
		\param a_rhs [in] The vector that is being subtracted.
		\return A vector wuth the results.
	*/
	Vector2<T> operator - (const Vector2<T>& a_rhs) const
	{
		return Vector2<T>(x - a_rhs.x, y - a_rhs.y);
	}

	/*!
		\brief Subtraction and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector vector that your subtracting from.
	*/
	Vector2<T>& operator -= (const Vector2<T>& a_rhs)
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		return *this;
	}

	/*!
		\brief Multiplication operator overloder.
		\param scalar [in] The amount that you are multiplying vector by.
		\return A vector with the completed multiplication.
	*/
	Vector2<T> operator * (const float scalar) const
	{
		return Vector2<T>(x * scalar, y * scalar);
	}

	/*!
		\brief Multiplication operator.
		\param a_rhs [in] The vector that is being used to multiply this vector.
		\return A vector with the results.
	*/
	Vector2<T> operator * (const Vector2<T> a_rhs) const
	{
		return Vector2<T>(x * a_rhs.x, y * a_rhs.y);
	}

	/*!
		\brief Multiplication operator overload.
		\param scalar [in] The varable that the vector is being multiplied by.
		\return The current vector by reference.
	*/
	Vector2<T> & operator * (const float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2<T> & operator *= (const Vector2<T> a_rhs)
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		return *this;
	}

	/*!
		\brief Division operator overloder.
		\param The amount that you are dividing vector by.
		\return A vector with the completed division.
	*/
	Vector2<T> operator / (float scalar) const
	{
		return Vector2<T>(x / scalar, y / scalar);
	}

	/*!
		\brief Division and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector that your subtracting from.
	*/
	Vector2<T>& operator /= (float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	/*!
		\brief Equality operator overloder.
		\param The vector that are copying over the top of the current one.
		\return The pointer to the current vector.
	*/
	Vector2<T>& operator = (const Vector2<T>& a_rhs)
	{
		x = a_rhs.x;
		y = a_rhs.y;
		return *this;
	}

	//! \brief Returns the distance between 0,0,0 and the coordinate.
	float magnitude() const
	{
		return std::sqrt(x * x + y * y);
	}

	//! \brief Returns squared magnitude.
	float square_magnitude()
	{
		return x * x + y * y;
	}
	//! \brief Returns the normalised vector.
	Vector2<T> normalized() const
	{
		float temp_mag = magnitude();
		return (*this / temp_mag);
	}

	//! \brief Normalised the vector.
	Vector2<T>& normalize()
	{
		*this = this->normalized();
		return *this;
	}
};

#endif // !VECTOR2_H

