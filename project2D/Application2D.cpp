#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() 
{

}

Application2D::~Application2D() 
{

}

bool Application2D::startup() 
{

	m_2dRenderer = new aie::Renderer2D();

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

	mars = new game_object(m_2dRenderer, m_mars_texture, { 0.0f, 400.0f * size_adjustment }, 0.0f,
		{ 40.0f * size_adjustment, 40.0f * size_adjustment });
	mars->set_parent(sun);
	mars->set_global_orbit(1.5f * size_adjustment);
	mars->set_global_rotation(15.0f);

	jupiter = new game_object(m_2dRenderer, m_jupiter_texture, { 0.0f, 550.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	jupiter->set_parent(sun);
	jupiter->set_global_orbit(1.4f * size_adjustment);
	jupiter->set_global_rotation(15.0f);

	uranus = new game_object(m_2dRenderer, m_uranus_texture, { 0.0f, 750.0f * size_adjustment }, 0.0f,
		{ 60.0f * size_adjustment, 60.0f * size_adjustment });
	uranus->set_parent(sun);
	uranus->set_global_orbit(1.35f * size_adjustment);
	uranus->set_global_rotation(15.0f);

	saturn = new game_object(m_2dRenderer, m_saturn_texture, { 0.0f, 650.0f * size_adjustment }, 0.0f,
		{ 120.0f * size_adjustment, 60.0f * size_adjustment });
	saturn->set_parent(sun);
	saturn->set_global_orbit(1.7f * size_adjustment);
	saturn->set_global_rotation(0.0f);

	mercury = new game_object(m_2dRenderer, m_mercury_texture, { 0.0f, 150.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	mercury->set_parent(sun);
	mercury->set_global_orbit(1.1f * size_adjustment);
	mercury->set_global_rotation(15.0f);

	venus = new game_object(m_2dRenderer, m_venus_texture, { 0.0f, 220.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	venus->set_parent(sun);
	venus->set_global_orbit(1.3f * size_adjustment);
	venus->set_global_rotation(15.0f);

	earth = new game_object(m_2dRenderer, m_earth_texture, { 0.0f, 300.0f * size_adjustment }, 0.0f,
		{ 50.0f * size_adjustment, 50.0f * size_adjustment });
	earth->set_parent(sun);
	earth->set_global_orbit(3.14159f / 2.0f * size_adjustment);
	earth->set_global_rotation(15.0f);

	moon = new game_object(m_2dRenderer, m_moon_texture, { 0.0f, 30.0f * size_adjustment }, 0.0f, { 15.0f * size_adjustment, 15.0f * size_adjustment });
	moon->set_parent(earth);
	//moon->m_orbit_speed = -moon->get_global_rotation() + 0.5 * size_adjustment;
	moon->set_global_orbit(0.5 * size_adjustment);
	moon->set_global_rotation(moon->get_parent()->get_rotation_speed());




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
}

void Application2D::update(float deltaTime)
{
	// Update planets
	sun->update(deltaTime);

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

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