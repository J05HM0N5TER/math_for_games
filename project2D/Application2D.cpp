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

	// Set textures
	m_sun_texture = new aie::Texture("./textures/the_sun.png");
	m_moon_texture = new aie::Texture("./textures/the_moon.png");
	m_earth_texture = new aie::Texture("./textures/earth.png");
	m_mars_texture = new aie::Texture("./textures/mars.png");
	m_jupiter_texture = new aie::Texture("./textures/jupiter.png");
	m_saturn_texture = new aie::Texture("./textures/saturn.png");
	m_mercury_texture = new aie::Texture("./textures/mercury.png");
	m_venus_texture = new aie::Texture("./textures/venus.png");
	m_uranus_texture = new aie::Texture("./textures/uranus.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);


	float size_adjustment = 0.6f;

	// -Sun-
	sun = new game_object(m_2dRenderer, m_sun_texture, { 640.0f, 340.0f }, 0.0f, { 150.0f * size_adjustment, 150.0f * size_adjustment });
	planets.push_back(sun);
	sun->set_collider(new circle(sun->get_postion(), sun->get_size().x / 2));

	// -Mars-
	// Create planet.
	mars = new game_object(m_2dRenderer, m_mars_texture, { 0.0f, 400.0f * size_adjustment }, 0.0f,
		{ 40.0f * size_adjustment, 40.0f * size_adjustment });
	// Set the parent of the planet (where it gets the transform from to calculate world transform.)
	mars->set_parent(sun);
	// Set the global orbit speed (sets it so that the rotation of the parent doesn't effect it.)
	mars->set_global_orbit(1.5f * size_adjustment);
	// Set the global rotation speed (sets it so the orbit and other factors doesn't effect it.)
	mars->set_global_rotation(15.0f);
	// Add it to the vector of planets.
	planets.push_back(mars);
	// Set the collision for the planet.
	mars->set_collider(new circle(mars->get_postion(), mars->get_size().x / 2));

	// -Jupiter-
	jupiter = new game_object(m_2dRenderer, m_jupiter_texture, { 0.0f, 550.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	jupiter->set_parent(sun);
	jupiter->set_global_orbit(1.4f * size_adjustment);
	jupiter->set_global_rotation(15.0f);
	planets.push_back(jupiter);
	jupiter->set_collider(new circle(jupiter->get_postion(), jupiter->get_size().x / 2));

	// -Uranus-
	uranus = new game_object(m_2dRenderer, m_uranus_texture, { 0.0f, 750.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	uranus->set_parent(sun);
	uranus->set_global_orbit(1.35f * size_adjustment);
	uranus->set_global_rotation(15.0f);
	planets.push_back(uranus);
	uranus->set_collider(new circle(uranus->get_postion(), uranus->get_size().x / 2));

	// -Saturn-
	saturn = new game_object(m_2dRenderer, m_saturn_texture, { 0.0f, 650.0f * size_adjustment }, 0.0f,
		{ 120.0f * size_adjustment, 60.0f * size_adjustment });
	saturn->set_parent(sun);
	saturn->set_global_orbit(1.7f * size_adjustment);
	saturn->set_global_rotation(0.0f);
	planets.push_back(saturn);
	saturn->set_collider(new circle(saturn->get_postion(), saturn->get_size().x / 2));

	// -Mercury-
	mercury = new game_object(m_2dRenderer, m_mercury_texture, { 0.0f, 150.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	mercury->set_parent(sun);
	mercury->set_global_orbit(1.1f * size_adjustment);
	mercury->set_global_rotation(15.0f);
	planets.push_back(mercury);
	mercury->set_collider(new circle(mercury->get_postion(), mercury->get_size().x / 2));

	// -Venus-
	venus = new game_object(m_2dRenderer, m_venus_texture, { 0.0f, 220.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	venus->set_parent(sun);
	venus->set_global_orbit(1.3f * size_adjustment);
	venus->set_global_rotation(15.0f);
	planets.push_back(venus);
	venus->set_collider(new circle(venus->get_postion(), venus->get_size().x / 2));

	// -Earth-
	earth = new game_object(m_2dRenderer, m_earth_texture, { 0.0f, 300.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	earth->set_parent(sun);
	earth->set_global_orbit(3.14159f / 2.0f * size_adjustment);
	earth->set_global_rotation(15.0f);
	planets.push_back(earth);
	earth->set_collider(new circle(earth->get_postion(), earth->get_size().x / 2));

	// -The moon-
	moon = new game_object(m_2dRenderer, m_moon_texture, { 0.0f, 30.0f * size_adjustment }, 0.0f, { 15.0f * size_adjustment, 15.0f * size_adjustment });
	moon->set_parent(earth);
	moon->set_global_orbit(0.5f * size_adjustment);
	moon->set_global_rotation(moon->get_parent()->get_rotation_speed());
	planets.push_back(moon);
	moon->set_collider(new circle(moon->get_postion(), moon->get_size().x / 2));

	// Set the input.
	input = aie::Input::getInstance();

	// -Ship-
	m_player_texture = new aie::Texture("./textures/ship.png");
	m_player = new game_object(m_2dRenderer, m_player_texture, { 100, 100 }, 0.0f, { 85, 85 });
	m_player->set_collider(new circle(m_player->get_postion(), m_player->get_size().x / 2));

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
	}
	// Delete player texture.
	if (m_player->get_texture())
	{
		delete m_player->get_texture();
	}
	// Delete player.
	delete m_player;


	// For each planet
	for (int i = (int)planets.size() - 1; i >= 0; i--)
	{
		// Delete colider.
		if (planets[i]->get_collider())
		{
			delete planets[i]->get_collider();
		}
		// Delete texture.
		if (planets[i]->get_texture())
		{
			delete planets[i]->get_texture();
		}
		// Delete game_object.
		game_object* temp = planets[i];
		planets.erase(planets.begin() + i);
		delete temp;
	}

}

void Application2D::update(float deltaTime)
{
	// Update planets
	sun->update(deltaTime);

	// Update timer.
	m_timer += deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_R))
	{
		m_player->is_valid = true;
	}

	// ---Player controls---
	float acceleration_speed = 50.0f;
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
		for (size_t i = 0; i < planets.size(); i++)
		{
			if (planets[i]->get_collider() && m_player->get_collider() &&
				collision_manager::circle_to_circle(*m_player->get_collider(), *planets[i]->get_collider()))
			{
				m_player->is_valid = false;
			}
		}
	}

	/*
	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;

	m_2dRenderer->setCameraPos(camPosX, camPosY);
	*/

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw()
{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Draw planets.
	sun->draw();

	// Draw player/ship
	m_player->draw();

	// Draw line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// Calculate text position.
	char escape_text[] = "Press ESC to quit!";
	short arrow_instruction_position = 720 - 64 - m_font->getStringHeight(escape_text);
	char restart_text[] = "R to restart plane.";

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, escape_text, 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Arrow keys to move plane.", 0, arrow_instruction_position);
	m_2dRenderer->drawText(m_font, restart_text, 0, arrow_instruction_position - m_font->getStringHeight(restart_text));

	// done drawing sprites
	m_2dRenderer->end();
}