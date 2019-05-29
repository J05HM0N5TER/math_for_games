#include "game_object.h"

game_object::game_object(aie::Renderer2D* a_renderer, aie::Texture* a_texture, const Vector2 a_position, 
	const float a_z_rotation, const Vector2 a_size /*= { 0.0f, 0.0f }*/,
	const float a_spin_speed /*= 0.0f*/, const float a_orbit_speed /*= 0.0f*/) :
	m_renderer(a_renderer), m_rotation_speed(a_spin_speed), m_orbit_speed(a_orbit_speed), m_position(a_position),
	m_current_rotation(a_z_rotation), m_size(a_size)
{
	m_texture = a_texture;
	m_parent = nullptr;

	m_local_transform.setRotateZ(m_current_rotation);
	m_local_transform.position = { a_position.x, a_position.y, 1.0f };

	m_speed = 0.0f;
	m_acceleration = 0.0f;
	m_max_speed = 0.0f;
}

void game_object::update(const float a_delta_time)
{
	// Acceleration math.
	m_speed += m_acceleration * a_delta_time;
	// Limit speed to max speed and negative max speed.
	if (m_speed > m_max_speed)
	{
		m_speed = m_max_speed;
	}
	else if (m_speed < -m_max_speed)
	{
		m_speed = -m_max_speed;
	}

	// Calculate based on speed.
	m_local_transform.position += m_local_transform.forwards * m_speed * a_delta_time;

	// Matrix that the transformations are applied to.
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
		// Calculate the global position of the earth off the sun position.
		m_world_transform = m_parent->get_world_matrix() * m_local_transform;
	}
	else
	{
		m_world_transform = m_local_transform;
	}

	// loop though all children and call update for them.
	for (size_t i = 0; i < m_children.size(); i++)
	{
		m_children[i]->update(a_delta_time);
	}
}

void game_object::draw()
{
	m_renderer->drawSpriteTransformed3x3(m_texture, 
		m_world_transform, m_size.x, m_size.y);

	// loop though all children and call draw for them.
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

const float game_object::get_global_rotation() const
{
	game_object* current_game_object;
	float rotaion_counter = 0.0f;

	// Checks if the game_object has an assigned parent.
	if (m_parent)
	{
		current_game_object = this->m_parent;

		while (current_game_object != nullptr)
		{
			rotaion_counter += current_game_object->m_orbit_speed + current_game_object->m_rotation_speed;
			current_game_object = current_game_object->get_parent();
		}
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

void game_object::set_orbit_speed(const float & a_orbit_speed)
{
	m_orbit_speed = a_orbit_speed;
}

const float & game_object::get_orbit_speed() const
{
	return m_orbit_speed;
}

const float & game_object::get_rotation_speed() const
{
	return m_rotation_speed;
}

void game_object::set_parent(game_object * a_parent)
{
	m_parent = a_parent;
	m_parent->add_child(this);
}

game_object * game_object::get_parent() const
{
	return m_parent;
}

void game_object::add_child(game_object * a_child)
{
	m_children.push_back(a_child);
}

void game_object::set_size(const Vector2 & a_size)
{
	m_size = a_size;
}

const Vector2 & game_object::get_size() const
{
	return m_size;
}

void game_object::set_acceleration(const float & a_acceleration)
{
	m_acceleration = a_acceleration;
}

const float game_object::get_acceleration() const
{
	return m_acceleration;
}

void game_object::set_speed(const float & a_speed)
{
	m_speed = a_speed;
}

const float & game_object::get_speed() const
{
	return m_speed;
}
