#include "player.h"
#include <iostream>

player::player(aie::Renderer2D * a_renderer, aie::Texture * a_texture, aie::Input* a_input, const Vector2 a_position) :
	game_object(a_renderer, a_texture, a_position, 0.0f), m_input(a_input)
{
	//set_size(Vector2(m_texture->getWidth(), m_texture->getHeight()));
	m_collider = new circle(a_position, (float)m_texture->getWidth());
	is_valid = true;
}

player::~player()
{
}

void player::update(const float a_delta_time)
{
	update_transform(a_delta_time);
	std::cout << "current acceleration: " << m_acceleration << std::endl;
	std::cout << "Current speed: " << m_speed << std::endl;
}
