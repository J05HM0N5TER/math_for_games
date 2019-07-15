#include "circle.h"
#include <cmath>

const float circle::DEFAULT_RADUS = 5.0f;


circle::circle(const Vector2 & a_position /*= Vector2()*/, const float a_radus /*= DEFAULT_RADUS*/) :
	collider(shape::circle),
	m_position(a_position), m_radus(a_radus)
{}

void circle::set_radus(const float a_radus)
{
	m_radus = abs(a_radus);
}

const float circle::get_radus() const
{
	return m_radus;
}

const Vector2 circle::get_position() const
{
	return m_position;
}

void circle::set_position(const Vector2 & a_position)
{
	m_position = a_position;
}

circle & circle::operator=(const circle & a_rhs)
{
	this->m_radus = a_rhs.m_radus;
	this->m_position = a_rhs.m_position;

	return *this;
}

bool circle::operator==(const circle & a_rhs)
{
	return (this->get_radus() == a_rhs.get_radus() &&
		this->get_position() == a_rhs.get_position());
}

bool circle::operator!=(const circle & a_rhs)
{
	return !(*this == a_rhs);
}



