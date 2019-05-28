#include "Line.h"
#include <limits>

const Vector2 Line::DEFAULT_NORMAL = { 1.0f, 1.0f };

Line::Line(const Vector2 & a_normal /*= { 1.0f, 1.0f }*/, 
	const float a_distance /*= 0.0f*/) :
	Collider(shape::line),
	m_normal(a_normal),
	m_distance(a_distance)
{
	set_normal(m_normal);
}

const Vector2 Line::get_normal() const
{
	return Vector2();
}

void Line::set_normal(const Vector2 & a_normal)
{
	if (m_normal.magnitude() < std::numeric_limits<float>::min())
	{
		m_normal = DEFAULT_NORMAL;
	}
	else
	{
		m_normal.normalise();
	}
}

const float Line::get_distance() const
{
	return m_distance;
}

void Line::set_distance(const float a_distance)
{
	m_distance = a_distance;
}
