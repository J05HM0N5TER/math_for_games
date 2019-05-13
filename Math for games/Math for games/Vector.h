//! \brief Class for a 2D vector.

#pragma once
#ifndef VECTOR_H
#define VECTOR_H

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
	float& operator[] (const size_t a_index)
	{
		_STL_ASSERT((a_index < 2), "Vector 2 index out of range");
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


template <typename T>
class Vector3
{
public:
	Vector3<T>() {};
	Vector3<T>(const T a_x, const T a_y, const T a_z) : x(a_x), y(a_y), z(a_z) {}

	union
	{
		struct
		{
			T x;
			T y;
			T z;
		};
		T data[3];
	};

	/*!
		\brief Subscript operator overload, used for direct access.
		\param a_index [in] The index that the user is trying to access.
	*/
	float& operator[] (const size_t a_index)
	{
		_STL_ASSERT((a_index < 3), "Vector 3 index out of range");
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
		\brief Addition operator overload.
		\param The vector that your plussing to this one.
		\return A vector with the sum of both vectors being added together.
	*/
	Vector3<T> operator + (const Vector3<T>& a_rhs) const
	{
		return Vector3<T>(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
	}

	/*!
		\brief Addition and equality overload.
		\param a_rhs [in] The vector that is being added.
		\return The pointer to the current vector.
	*/
	Vector3<T>& operator += (const Vector3<T> a_rhs)
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		return *this;
	}

	/*!
		\brief Subtraction operator overload.
		\param a_rhs [in] The vector that is being subtracted.
		\return A vector wuth the results.
	*/
	Vector3<T> operator - (const Vector3<T>& a_rhs) const
	{
		return Vector3<T>(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
	}

	/*!
		\brief Subtraction and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector vector that your subtracting from.
	*/
	Vector3<T>& operator -= (const Vector3<T>& a_rhs)
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		return *this;
	}

	/*!
		\brief Multiplication operator overloder.
		\param scalar [in] The amount that you are multiplying vector by.
		\return A vector with the completed multiplication.
	*/
	Vector3<T> operator * (const float scalar) const
	{
		return Vector3<T>(x * scalar, y * scalar, z * scalar);
	}

	/*!
		\brief Multiplication operator.
		\param a_rhs [in] The vector that is being used to multiply this vector.
		\return A vector with the results.
	*/
	Vector3<T> operator * (const Vector3<T> a_rhs) const
	{
		return Vector3<T>(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
	}

	/*!
		\brief Multiplication operator overload.
		\param scalar [in] The varable that the vector is being multiplied by.
		\return The current vector by reference.
	*/
	Vector3<T> & operator * (const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vector3<T> & operator *= (const Vector3<T> a_rhs)
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		z *= a_rhs.z;
		return *this;
	}

	/*!
		\brief Division operator overloder.
		\param The amount that you are dividing vector by.
		\return A vector with the completed division.
	*/
	Vector3<T> operator / (float scalar) const
	{
		return Vector3<T>(x / scalar, y / scalar, z / scalar);
	}

	/*!
		\brief Division and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector that your subtracting from.
	*/
	Vector3<T>& operator /= (float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	/*!
		\brief Equality operator overloder.
		\param The vector that are copying over the top of the current one.
		\return The pointer to the current vector.
	*/
	Vector3<T>& operator = (const Vector3<T>& a_rhs)
	{
		x = a_rhs.x;
		y = a_rhs.y;
		z = a_rhs.z;
		return *this;
	}

	//! \brief Returns the distance between 0,0,0 and the coordinate.
	float magnitude() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	//! \brief Returns squared magnitude.
	float square_magnitude()
	{
		return x * x + y * y + z * z;
	}
	//! \brief Returns the normalised vector.
	Vector3<T> normalized() const
	{
		float temp_mag = magnitude();
		return (*this / temp_mag);
	}

	//! \brief Normalised the vector.
	Vector3<T>& normalize()
	{
		*this = this->normalized();
		return *this;
	}
};

//template <typename T>
//class Vector4
//{
//public:
//	Vector4<T>() {};
//	Vector4<T>(const T a_x, const T a_y, const T a_z, const T a_w) : x(a_x), y(a_y), z(a_z), w(a_w) {}
//
//	union
//	{
//		struct
//		{
//			T x;
//			T y;
//			T z;
//			T w;
//		};
//		T data[4];
//	};
//
//	/*!
//		\brief Subscript operator overload, used for direct access.
//		\param a_index [in] The index that the user is trying to access.
//	*/
//	float& operator[] (const size_t a_index)
//	{
//		_STL_ASSERT((a_index < 4), "Vector 4 index out of range");
//		return data[a_index];
//	}
//
//	//! \brief Casting mutable float* operator overloading.
//	explicit operator float* ()
//	{
//		return data;
//	}
//	//! \brief Casting read only float* operator overloading.
//	explicit operator const float* () const
//	{
//		return data;
//	}
//
//	/*!
//		\brief Addition operator overloder.
//		\param The vector that your plussing to this one.
//		\return A vector with the sum of both vectors being added together.
//	*/
//	Vector4 operator + (const Vector4& a_rhs) const
//	{
//		return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
//	}
//
//	/*!
//		\brief Subtraction and equality operator overloder.
//		\param The vector that your plussing to this one.
//		\return The pointer to the current vector vector that your subtracting from.
//	*/
//	Vector4& operator -= (const Vector4& a_rhs)
//	{
//		x -= a_rhs.x;
//		y -= a_rhs.y;
//		z -= a_rhs.z;
//		w -= a_rhs.w;
//		return *this;
//	}
//
//	/*!
//		\brief Multiplication operator overloder.
//		\param The amount that you are multiplying vector by.
//		\return A vector with the completed multiplication.
//	*/
//	Vector4 operator * (float scalar) const
//	{
//		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
//	}
//
//	/*!
//		\brief Division and equality operator overloder.
//		\param The vector that your plussing to this one.
//		\return The pointer to the current vector that your subtracting from.
//	*/
//	Vector4& operator /= (float scalar)
//	{
//		x /= scalar;
//		y /= scalar;
//		z /= scalar;
//		w /= scalar;
//		return *this;
//	}
//
//	/*!
//		\brief Equality operator overloder.
//		\param The vector that are copying over the top of the current one.
//		\return The pointer to the current vector.
//	*/
//	Vector4& operator = (const Vector4& a_rhs)
//	{
//		x = a_rhs.x;
//		y = a_rhs.y;
//		z = a_rhs.z;
//		w = a_rhs.w;
//		return *this;
//	}
//
//	//! \brief Returns the distance between 0,0,0 and the coordinate.
//	T magnitude() const
//	{
//		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(w , 2));
//	}
//
//	//! \brief Returns the direction from 0,0,0;
//	T normalized() const
//	{
//		T temp_mag = magnitude();
//		return ((x / temp_mag) + (y / temp_mag) + (z / temp_mag) + (w / temp_mag));
//	}
//};


#endif // !VECTOR_H
