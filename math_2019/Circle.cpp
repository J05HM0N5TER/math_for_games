#include "Circle.h"
#include <cmath>

const float Circle::DEFAULT_RADUS = 5.0f;


Circle::Circle(const Vector2 & a_position /*= Vector2()*/, const float a_radus /*= DEFAULT_RADUS*/) :
	Collider(shape::circle),
	m_position(a_position), m_radus(a_radus)
{}

void Circle::set_radus(const float a_radus)
{
	m_radus = abs(a_radus);
}

const float Circle::get_radus() const
{
	return m_radus;
}

const Vector2 Circle::get_position() const
{
	return Vector2();
}

void Circle::set_position(const Vector2 & a_position)
{
}



