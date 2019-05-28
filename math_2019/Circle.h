#pragma once
#include "Vector2.h"
#include "Collider.h"
class Circle : public Collider
{
public:

	static const float DEFAULT_RADUS;

	Circle(const Vector2 & a_position = Vector2(), const float a_radus = DEFAULT_RADUS);

	/*	\brief Sets the radus to the absolute value of the argument.
		\param The new radus as a float
	*/
	void set_radus(const float a_radus);
	const float get_radus() const;


	const Vector2 get_position() const;
	void set_position(const Vector2 & a_position);

private:
	float m_radus = 0.0f;
	Vector2 m_position;
};


