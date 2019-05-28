#include "aligned_bounding_box.h"
#include <cmath>

const Vector2 aligned_bounding_box::DEFAULT_EXTENTS = { 5.0f, 5.0f };

aligned_bounding_box::aligned_bounding_box(
	const Vector2 & a_position /*= Vector2()*/, 
	const Vector2 & a_extents /*= DEFAULT_EXTENTS*/) :
	Collider(shape::aabb),
	m_position(a_position), m_extents(a_extents)
{
}

const Vector2 aligned_bounding_box::get_position() const
{
	return m_position;
}

void aligned_bounding_box::set_position(const Vector2 & a_position)
{
	m_position = a_position;
}

const Vector2 aligned_bounding_box::get_extents() const
{
	return m_extents;
}

void aligned_bounding_box::set_extents(const Vector2 & a_extents)
{
	m_extents = { abs(a_extents.x), abs(a_extents.y) };
}

const float aligned_bounding_box::get_width() const
{
	return m_extents.x;
}

const float aligned_bounding_box::get_height() const
{
	return m_extents.y;
}

const Vector2 aligned_bounding_box::get_max() const
{
	return m_position + 0.5f * m_extents;
}

const Vector2 aligned_bounding_box::get_min() const
{
	return m_position - 0.5f * m_extents;
}

