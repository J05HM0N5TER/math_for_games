#include "Application2D.h"
#include "Texture.h"
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

	sun = new game_object(m_2dRenderer, m_sun_texture, { 640.0f, 340.0f }, 0.0f, { 150.0f * size_adjustment, 150.0f * size_adjustment });
	planets.push_back(sun);
	sun->set_collider(new circle(sun->get_postion(), sun->get_size().x));

	mars = new game_object(m_2dRenderer, m_mars_texture, { 0.0f, 400.0f * size_adjustment }, 0.0f,
		{ 40.0f * size_adjustment, 40.0f * size_adjustment });
	mars->set_parent(sun);
	mars->set_global_orbit(1.5f * size_adjustment);
	mars->set_global_rotation(15.0f);
	planets.push_back(mars);
	mars->set_collider(new circle(mars->get_postion(), mars->get_size().x));


	jupiter = new game_object(m_2dRenderer, m_jupiter_texture, { 0.0f, 550.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	jupiter->set_parent(sun);
	jupiter->set_global_orbit(1.4f * size_adjustment);
	jupiter->set_global_rotation(15.0f);
	planets.push_back(jupiter);
	jupiter->set_collider(new circle(jupiter->get_postion(), jupiter->get_size().x));

	uranus = new game_object(m_2dRenderer, m_uranus_texture, { 0.0f, 750.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	uranus->set_parent(sun);
	uranus->set_global_orbit(1.35f * size_adjustment);
	uranus->set_global_rotation(15.0f);
	planets.push_back(uranus);
	uranus->set_collider(new circle(uranus->get_postion(), uranus->get_size().x));

	saturn = new game_object(m_2dRenderer, m_saturn_texture, { 0.0f, 650.0f * size_adjustment }, 0.0f,
		{ 120.0f * size_adjustment, 60.0f * size_adjustment });
	saturn->set_parent(sun);
	saturn->set_global_orbit(1.7f * size_adjustment);
	saturn->set_global_rotation(0.0f);
	planets.push_back(saturn);
	saturn->set_collider(new circle(saturn->get_postion(), saturn->get_size().x));

	mercury = new game_object(m_2dRenderer, m_mercury_texture, { 0.0f, 150.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	mercury->set_parent(sun);
	mercury->set_global_orbit(1.1f * size_adjustment);
	mercury->set_global_rotation(15.0f);
	planets.push_back(mercury);
	mercury->set_collider(new circle(mercury->get_postion(), mercury->get_size().x));

	venus = new game_object(m_2dRenderer, m_venus_texture, { 0.0f, 220.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	venus->set_parent(sun);
	venus->set_global_orbit(1.3f * size_adjustment);
	venus->set_global_rotation(15.0f);
	planets.push_back(venus);
	venus->set_collider(new circle(venus->get_postion(), venus->get_size().x));

	earth = new game_object(m_2dRenderer, m_earth_texture, { 0.0f, 300.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	earth->set_parent(sun);
	earth->set_global_orbit(3.14159f / 2.0f * size_adjustment);
	earth->set_global_rotation(15.0f);
	planets.push_back(earth);
	earth->set_collider(new circle(earth->get_postion(), earth->get_size().x));

	moon = new game_object(m_2dRenderer, m_moon_texture, { 0.0f, 30.0f * size_adjustment }, 0.0f, { 15.0f * size_adjustment, 15.0f * size_adjustment });
	moon->set_parent(earth);
	//moon->m_orbit_speed = -moon->get_global_rotation() + 0.5 * size_adjustment;
	moon->set_global_orbit(0.5f * size_adjustment);
	moon->set_global_rotation(moon->get_parent()->get_rotation_speed());
	planets.push_back(moon);
	moon->set_collider(new circle(moon->get_postion(), moon->get_size().x));

	input = aie::Input::getInstance();


	// Ship
	m_player_texture = new aie::Texture("./textures/ship.png");
	m_player = new game_object(m_2dRenderer, m_player_texture, { 0, 0 }, 0.0f, { 100, 100 });


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

	// ---Delete all textures---
	delete m_mars_texture;
	delete m_uranus_texture;
	delete m_jupiter_texture;
	delete m_mercury_texture;
	delete m_venus_texture;
	delete m_saturn_texture;
	delete m_earth_texture;
	delete m_sun_texture;
	delete m_moon_texture;
	delete m_player_texture;

	// ---Delete all game_objects--
	delete sun;
	delete earth;
	delete moon;
	delete mars;
	delete jupiter;
	delete saturn;
	delete mercury;
	delete venus;
	delete uranus;
	delete m_player;
}

void Application2D::update(float deltaTime)
{
	// input example
	//input = aie::Input::getInstance();

	// Update planets
	sun->update(deltaTime);

	m_timer += deltaTime;

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


	if (m_player->is_valid)
	{
		m_player->update(deltaTime);
		for (size_t i = 0; i < planets.size(); i++)
		{
			if (planets[i]->get_collider() &&
				collision_manager::circle_to_circle(*m_player->get_collider(), *planets[i]->get_collider()))
			{
				m_player->is_valid = false;
			}
		}
	}

	//for (size_t i = 0; i < planets.size(); i++)
	//{
	//	collision_manager::circle_to_circle()
	//}

	//// Update the camera position using the arrow keys
	//float camPosX;
	//float camPosY;
	//m_2dRenderer->getCameraPos(camPosX, camPosY);

	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//	camPosY += 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//	camPosY -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	//	camPosX -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//	camPosX += 500.0f * deltaTime;

	//m_2dRenderer->setCameraPos(camPosX, camPosY);

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

	m_player->draw();

	// Draw line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}