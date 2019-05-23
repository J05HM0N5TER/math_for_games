#include "game_object.h"



game_object::game_object(aie::Renderer2D* a_renderer, aie::Texture* a_texture, const Vector2 a_position, const float a_z_rotation, const Vector2 a_size /*= { 0.0f, 0.0f }*/,
	const float a_spin_speed /*= 0.0f*/, const float a_orbit_speed /*= 0.0f*/) :
	m_renderer(a_renderer), m_rotation_speed(a_spin_speed), m_orbit_speed(a_orbit_speed), m_position(a_position),
	m_current_rotation(a_z_rotation), m_size(a_size)
{
	m_texture = a_texture;
	m_parent = nullptr;

	m_local_transform.setRotateZ(m_current_rotation);
	m_local_transform.position = { a_position.x, a_position.y, 1.0f };
}


game_object::~game_object()
{
}

void game_object::update(const float a_delta_time)
{


	Matrix3 rotation_matrix;

	// Rotate the object.
	rotation_matrix.setRotateZ(a_delta_time * m_rotation_speed);
	m_local_transform *= rotation_matrix;

	// Set orbit speed.
	rotation_matrix.setRotateZ(a_delta_time * m_orbit_speed);
	m_local_transform = rotation_matrix * m_local_transform;

	// childing
	if (m_parent)
	{
		// Calculate the global postion of the earth off the sun position.
		m_world_transform = m_parent->get_world_matrix() * m_local_transform;
	}
	else
	{
		m_world_transform = m_local_transform;
	}

	for (size_t i = 0; i < m_children.size(); i++)
	{
		m_children[i]->update(a_delta_time);
	}
}

void game_object::draw()
{
	m_renderer->drawSpriteTransformed3x3(m_texture, m_world_transform, m_size.x, m_size.y);

	for (size_t i = 0; i < m_children.size(); i++)
	{
		m_children[i]->draw();
	}
}

const Matrix3 & game_object::get_world_matrix() const
{
	return m_world_transform;
}

const Vector2 & game_object::get_postion() const
{
	return m_position;
}


void game_object::set_local_position(const Vector2 & a_position)
{
	m_position = a_position;
}


float game_object::get_global_rotation()
{
	game_object* current_game_object = m_parent;
	float rotaion_counter = 0.0f;

	while (current_game_object)
	{
		rotaion_counter += current_game_object->m_orbit_speed + current_game_object->m_rotation_speed;
		current_game_object = current_game_object->get_parent();
	}

	rotaion_counter += m_rotation_speed + m_orbit_speed;

	return rotaion_counter;
}

void game_object::set_global_rotation(const float& a_rotaion_speed)
{
	m_rotation_speed = -this->get_global_rotation() + a_rotaion_speed;
}

void game_object::set_global_orbit(const float & a_orbit_speed)
{
	m_orbit_speed = -this->get_global_rotation() + a_orbit_speed;
}

void game_object::set_parent(game_object * a_parent)
{
	m_parent = a_parent;
	m_parent->add_child(this);
}

game_object * game_object::get_parent()
{
	return m_parent;
}

void game_object::add_child(game_object * a_child)
{
	m_children.push_back(a_child);
}
