#include "Vector4.h"

Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{};

Vector4::Vector4(const float a_x, const float a_y, 
	const float a_z, const float a_w) : 
	x(a_x), y(a_y), z(a_z), w(a_w) 
{}

float& Vector4::operator[] (const size_t a_index)
{
	_STL_ASSERT((a_index < 4), "Vector 4 index out of range");
	return data[a_index];
}

Vector4::operator float* ()
{
	return data;
}

Vector4::operator const float* () const
{
	return data;
}

Vector4 Vector4::operator + (const Vector4& a_rhs) const
{
	return Vector4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
}

Vector4& Vector4::operator += (const Vector4 a_rhs)
{
	x += a_rhs.x;
	y += a_rhs.y;
	z += a_rhs.z;
	w += a_rhs.w;
	return *this;
}

Vector4 Vector4::operator - (const Vector4& a_rhs) const
{
	return Vector4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

Vector4& Vector4::operator -= (const Vector4& a_rhs)
{
	x -= a_rhs.x;
	y -= a_rhs.y;
	z -= a_rhs.z;
	return *this;
}

Vector4 Vector4::operator * (const float scalar) const
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator * (const Vector4 a_rhs) const
{
	return Vector4(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z, w * a_rhs.w);
}

Vector4 & Vector4::operator * (const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector4 & Vector4::operator *= (const Vector4 a_rhs)
{
	x *= a_rhs.x;
	y *= a_rhs.y;
	z *= a_rhs.z;
	return *this;
}

Vector4 Vector4::operator / (float scalar) const
{
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

Vector4& Vector4::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

Vector4& Vector4::operator = (const Vector4& a_rhs)
{
	x = a_rhs.x;
	y = a_rhs.y;
	z = a_rhs.z;
	return *this;
}

float Vector4::square_magnitude()
{
	return x * x + y * y + z * z;
}

float Vector4::magnitude() const
{
	return std::sqrt(square_magnitude());
}

Vector4 Vector4::normalized() const
{
	float temp_mag = magnitude();
	return (*this / temp_mag);
}

Vector4& Vector4::normalize()
{
	*this = this->normalized();
	return *this;
}

float Vector4::dot(const Vector4& a_Vector4) const
{
	return (x * a_Vector4.x) + (y * a_Vector4.y) + (z * a_Vector4.z);
}

float Vector4::dot(const Vector4& a_vector_a, const Vector4& a_vector_b)
{
	return a_vector_a.dot(a_vector_b);
}

Vector4 Vector4::cross(const Vector4& a_Vector4) const
{
	return Vector4(y * a_Vector4.z - z * a_Vector4.y,
		z * a_Vector4.x - x * a_Vector4.z,
		x * a_Vector4.y - y * a_Vector4.x,
		w);
}

Vector4 Vector4::cross(const Vector4& a_vector_a, const Vector4& a_vector_b)
{
	return a_vector_a.cross(a_vector_b);
}