#include "Collider.h"



const Collider::shape Collider::get_shape() const
{
	return m_shape;
}

Collider::Collider(shape a_shape) : m_shape(a_shape)
{}

