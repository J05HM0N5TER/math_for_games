#include "Application2D.h"
#include "Font.h"
#include "Collision_manager.h"
#include <iostream>

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}

bool Application2D::startup()
{

	m_2dRenderer = new aie::Renderer2D();

	// When creating redistributable .exe change all '"../' to '"./'
	// Set textures
	m_sun_texture = new aie::Texture("../bin/textures/the_sun.png");
	m_moon_texture = new aie::Texture("../bin/textures/the_moon.png");
	m_earth_texture = new aie::Texture("../bin/textures/earth.png");
	m_mars_texture = new aie::Texture("../bin/textures/mars.png");
	m_jupiter_texture = new aie::Texture("../bin/textures/jupiter.png");
	m_saturn_texture = new aie::Texture("../bin/textures/saturn.png");
	m_mercury_texture = new aie::Texture("../bin/textures/mercury.png");
	m_venus_texture = new aie::Texture("../bin/textures/venus.png");
	m_uranus_texture = new aie::Texture("../bin/textures/uranus.png");

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);


	float size_adjustment = 0.6f;

	// -Sun-
	m_sun = new game_object(m_2dRenderer, m_sun_texture, { 640.0f, 340.0f }, 0.0f, 
		{ 150.0f * size_adjustment, 150.0f * size_adjustment }, 0.25f);
	m_planets.push_back(m_sun);
	m_sun->set_collider(new circle(m_sun->get_local_position(), m_sun->get_size().x / 2));

	// -Mars-
	// Create planet.
	m_mars = new game_object(m_2dRenderer, m_mars_texture, { 0.0f, 400.0f * size_adjustment }, 0.0f,
		{ 40.0f * size_adjustment, 40.0f * size_adjustment });
	// Set the parent of the planet (where it gets the transform from to calculate world transform.)
	m_mars->set_parent(m_sun);
	// Set the global orbit speed (sets it so that the rotation of the parent doesn't effect it.)
	m_mars->set_global_orbit(1.5f * size_adjustment);
	// Set the global rotation speed (sets it so the orbit and other factors doesn't effect it.)
	m_mars->set_global_rotation(15.0f);
	// Add it to the vector of planets.
	m_planets.push_back(m_mars);
	// Set the collision for the planet.
	m_mars->set_collider(new circle(m_mars->get_local_position(), m_mars->get_size().x / 2));

	// -Jupiter-
	m_jupiter = new game_object(m_2dRenderer, m_jupiter_texture, { 0.0f, 550.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	m_jupiter->set_parent(m_sun);
	m_jupiter->set_global_orbit(1.4f * size_adjustment);
	m_jupiter->set_global_rotation(15.0f);
	m_planets.push_back(m_jupiter);
	m_jupiter->set_collider(new circle(m_jupiter->get_local_position(), m_jupiter->get_size().x / 2));

	// -Uranus-
	m_uranus = new game_object(m_2dRenderer, m_uranus_texture, { 0.0f, 750.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	m_uranus->set_parent(m_sun);
	m_uranus->set_global_orbit(1.35f * size_adjustment);
	m_uranus->set_global_rotation(15.0f);
	m_planets.push_back(m_uranus);
	m_uranus->set_collider(new circle(m_uranus->get_local_position(), m_uranus->get_size().x / 2));

	// -Saturn-
	m_saturn = new game_object(m_2dRenderer, m_saturn_texture, { 0.0f, 650.0f * size_adjustment }, 0.0f,
		{ 120.0f * size_adjustment, 60.0f * size_adjustment });
	m_saturn->set_parent(m_sun);
	m_saturn->set_global_orbit(1.7f * size_adjustment);
	m_saturn->set_global_rotation(0.0f);
	m_planets.push_back(m_saturn);
	m_saturn->set_collider(new circle(m_saturn->get_local_position(), m_saturn->get_size().x / 2));

	// -Mercury-
	m_mercury = new game_object(m_2dRenderer, m_mercury_texture, { 0.0f, 150.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	m_mercury->set_parent(m_sun);
	m_mercury->set_global_orbit(1.1f * size_adjustment);
	m_mercury->set_global_rotation(15.0f);
	m_planets.push_back(m_mercury);
	m_mercury->set_collider(new circle(m_mercury->get_local_position(), m_mercury->get_size().x / 2));

	// -Venus-
	m_venus = new game_object(m_2dRenderer, m_venus_texture, { 0.0f, 220.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	m_venus->set_parent(m_sun);
	m_venus->set_global_orbit(1.3f * size_adjustment);
	m_venus->set_global_rotation(15.0f);
	m_planets.push_back(m_venus);
	m_venus->set_collider(new circle(m_venus->get_local_position(), m_venus->get_size().x / 2));

	// -Earth-
	m_earth = new game_object(m_2dRenderer, m_earth_texture, { 0.0f, 300.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	m_earth->set_parent(m_sun);
	m_earth->set_global_orbit(3.14159f / 2.0f * size_adjustment);
	m_earth->set_global_rotation(15.0f);
	m_planets.push_back(m_earth);
	m_earth->set_collider(new circle(m_earth->get_local_position(), m_earth->get_size().x / 2));

	// -The moon-
	m_moon = new game_object(m_2dRenderer, m_moon_texture, { 0.0f, 30.0f * size_adjustment }, 0.0f, 
		{ 15.0f * size_adjustment, 15.0f * size_adjustment });
	m_moon->set_parent(m_earth);
	m_moon->set_global_orbit(0.5f * size_adjustment);
	m_moon->set_global_rotation(m_moon->get_parent()->get_rotation_speed());
	m_planets.push_back(m_moon);
	m_moon->set_collider(new circle(m_moon->get_local_position(), m_moon->get_size().x / 2));

	// Set the input.
	input = aie::Input::getInstance();

	// -Ship-
	m_player_texture = new aie::Texture("../bin/textures/ship.png");
	m_player = new game_object(m_2dRenderer, m_player_texture, { 100, 100 }, 0.0f, { 85, 85 });
	m_player->set_collider(new circle(m_player->get_local_position(), m_player->get_size().x / 2));

	m_timer = 0;

	// Done to mess with the display.
	//clearScreen();

	return true;
}

void Application2D::shutdown()
{
	// Delete font.
	delete m_font;
	// Delete renderer.
	delete m_2dRenderer;

	// Delete player collider.
	if (m_player->get_collider())
	{
		delete m_player->get_collider();
		m_player->set_collider(nullptr);
	}
	// Delete player texture.
	if (m_player->get_texture())
	{
		delete m_player->get_texture();
		m_player->set_texture(nullptr);
	}
	// Delete player.
	delete m_player;


	// For each planet
	for (int i = (int)m_planets.size() - 1; i >= 0; i--)
	{
		// Delete colider.
		if (m_planets[i]->get_collider())
		{
			delete m_planets[i]->get_collider();
			m_planets[i]->set_collider(nullptr);
		}
		// Delete texture.
		if (m_planets[i]->get_texture())
		{
			delete m_planets[i]->get_texture();
			m_planets[i]->set_texture(nullptr);
		}
		// Delete game_object.
		game_object* temp = m_planets[i];
		m_planets.erase(m_planets.begin() + i);
		delete temp;
	}
}

void Application2D::update(float deltaTime)
{
	// Update planets
	m_sun->update(deltaTime);

	// Update timer.
	m_timer += deltaTime;

	// ---Player controls---
	float acceleration_speed = 100.0f;
	float rotation_speed = 5.0f;

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_player->set_acceleration(acceleration_speed);
	}
	// down
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_player->set_acceleration(-acceleration_speed);
	}
	else
	{
		m_player->set_acceleration(0.0f);
	}
	// left
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_player->set_rotation_speed(rotation_speed);
	}
	// right
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_player->set_rotation_speed(-rotation_speed);
	}
	else
	{
		m_player->set_rotation_speed(0.0f);
	}

	// ---Collision detection---
	if (m_player->is_valid)
	{
		m_player->update(deltaTime);
		for (size_t i = 0; i < m_planets.size(); i++)
		{
			if (m_planets[i]->get_collider() && m_player->get_collider() &&
				collision_manager::circle_to_circle(*m_player->get_collider(), 
					*m_planets[i]->get_collider()))
			{
				m_player->is_valid = false;
			}
		}
	}

	// exit the application [Esc].
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// Restart button [R].
	if (input->isKeyDown(aie::INPUT_KEY_R))
	{
		// Set to the player being alive.
		m_player->is_valid = true;

		// Reset rotation for the player.
		m_player->set_local_rotation(0.0f);

		// Reset speed for the player.
		m_player->set_speed(0.0f);

		// Set the position of the player to the start position.
		m_player->set_local_position({ 100.0f, 100.0f });
	}
}

void Application2D::draw()
{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Draw planets.
	m_sun->draw();

	// Draw player/ship
	m_player->draw();

	// Display text if player is dead.
	if (!m_player->is_valid)
	{
		char died_text[] = "You died!";
		m_2dRenderer->drawText(m_font, died_text, 
			m_player->get_local_position().x - (m_font->getStringWidth(died_text) / 2), 
			m_player->get_local_position().y + 64);

	}

	// Calculate text position.
	char escape_text[] = "Press ESC to quit!";
	float arrow_instruction_position = 720 - 64 - m_font->getStringHeight(escape_text);
	char restart_text[] = "R to restart plane.";

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, escape_text, 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Arrow keys to move plane.", 
		0, arrow_instruction_position);
	m_2dRenderer->drawText(m_font, restart_text, 0, 
		arrow_instruction_position - m_font->getStringHeight(restart_text));

	// done drawing sprites
	m_2dRenderer->end();
}