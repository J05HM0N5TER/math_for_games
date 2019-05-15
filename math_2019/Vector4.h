#pragma once
#pragma once
#ifndef VECTOR4_H
#define VECTOR4_H

#include <cassert>
#include <cmath>

class Vector4
{
public:
	Vector4();
	Vector4(const float a_x, const float a_y, const float a_z, const float a_w);

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];
	};

	/*!	\brief Subscript operator overload, used for direct access.
		\param a_index [in] The index that the user is trying to access.
	*/
	float& operator[] (const size_t a_index);

	//! \brief Casting mutable float* operator overloading.
	operator float* ();
	//! \brief Casting read only float* operator overloading.
	operator const float* () const;

	/*!	\brief Addition operator overload.
		\param The vector that your plussing to this one.
		\return A vector with the sum of both vectors being added together.
	*/
	Vector4 operator + (const Vector4& a_rhs) const;

	/*!	\brief Addition and equality overload.
		\param a_rhs [in] The vector that is being added.
		\return The pointer to the current vector.
	*/
	Vector4& operator += (const Vector4 a_rhs);

	/*!	\brief Subtraction operator overload.
		\param a_rhs [in] The vector that is being subtracted.
		\return A vector wuth the results.
	*/
	Vector4 operator - (const Vector4& a_rhs) const;

	/*!	\brief Subtraction and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector vector that your subtracting from.
	*/
	Vector4& operator -= (const Vector4& a_rhs);

	/*!	\brief Multiplication operator overloder.
		\param scalar [in] The amount that you are multiplying vector by.
		\return A vector with the completed multiplication.
	*/
	Vector4 operator * (const float scalar) const;

	/*!	\brief Multiplication operator.
		\param a_rhs [in] The vector that is being used to multiply this vector.
		\return A vector with the results.
	*/
	Vector4 operator * (const Vector4 a_rhs) const;

	/*!	\brief Multiplication operator overload.
		\param scalar [in] The varable that the vector is being multiplied by.
		\return The current vector by reference.
	*/
	Vector4 & operator * (const float scalar);

	/*!	\brief Multiplication and equality operator overloder.
		\param The vector that your Multiplying to this one.
		\return The pointer to the current vector that your Multiplying.
	*/
	Vector4 & operator *= (const Vector4 a_rhs);

	/*!	\brief Division operator overloder.
		\param The amount that you are dividing vector by.
		\return A vector with the completed division.
	*/
	Vector4 operator / (float scalar) const;

	/*!	\brief Division and equality operator overloder.
		\param The vector that your plussing to this one.
		\return The pointer to the current vector that your subtracting from.
	*/
	Vector4& operator /= (float scalar);

	/*!	\brief Equality operator overloder.
		\param The vector that are copying over the top of the current one.
		\return The pointer to the current vector.
	*/
	Vector4& operator = (const Vector4& a_rhs);

	//! \brief Returns squared magnitude.
	float square_magnitude() const;

	//! \brief Returns the distance between 0,0,0 and the coordinate.
	float magnitude() const;

	//! \brief Returns the normalised vector.
	Vector4 normalised() const;

	//! \brief Normalised the vector.
	Vector4& normalise();


	/*!	\brief Returns the dot product of two vectors.
		\param a_Vector4 [in] The second angle that is being compared.
		\return The dot product (ratio) of the difference in two vector angles.
		\warning Use normalised vectors otherwize product will be incorrect.
	*/
	float dot(const Vector4& a_Vector4) const;

	/*!	\brief Returns the dot product of two vectors.
		\param a_vector_a [in] The first angle that is being compared.
		\param a_vector_b [in] The first angle that is being compared.
		\return The dot product (ratio) of the difference in two vector angles.
		\warning Use normalised vectors otherwize product will be incorrect.
	*/
	static float dot(const Vector4& a_vector_a, const Vector4& a_vector_b);

	/*!	\brief Finds the vector perpendicular to the two angles supplies.
		\param a_Vector4 [in] The second angle that is being used to find the perpendicular.
		\return A Vector4 witht the perpendicular angle.
	*/
	Vector4 cross(const Vector4& a_Vector4) const;

	/*!	\brief Finds the vector perpendicular to the two angles supplies.
		\param a_Vector4 [in] The second angle that is being used to find the perpendicular.
		\return A Vector4 witht the perpendicular angle.
	*/
	static Vector4 cross(const Vector4& a_vector_a, const Vector4& a_vector_b);
};

Vector4 operator * (const float& a_lhs, const Vector4& a_rhs);

#endif // !VECTOR4_H

