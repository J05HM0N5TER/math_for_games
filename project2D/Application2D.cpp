#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_sun_texture = new aie::Texture("./textures/the_sun.png");
	m_moon_texture = new aie::Texture("./textures/the_moon.png");
	m_earth_texture = new aie::Texture("./textures/earth.png");
	m_station_texture = new aie::Texture("./textures/space_station.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	sun_world_transform.position = Vector3(640.0f, 340.0f, 1.0f);
	earth_local_transform.position = Vector3(0.0f, 200.0f, 1.0f);
	moon_local_transform.position = Vector3(0.0f, 70.0f, 1.0f);
	station_local_transform.position = Vector3(0.0f, 20.0f, 1.0f);

	earth_roation = 1.0f;
	earth_orbit = 3.14159f / 2.0f; // 90deg / second.
	
	moon_rotation = 3.14159f/* / 2.0f*/;
	moon_orbit = moon_rotation * 0.5f;

	Vector3 t = {1, 2, 3};

	station_rotation = 1;
	station_orbit = 5;

	m_timer = 0;

	// Done to mess with the display.
	//clearScreen();

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_sun_texture;
	delete m_moon_texture;
	delete m_earth_texture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	Matrix3 rotation_matrix;

	rotation_matrix.setRotateZ(deltaTime);

	// Rotates object by this rotation_matrix matrix.
	sun_world_transform *= rotation_matrix;

	// Ship spins same as parent.
	rotation_matrix.setRotateZ(deltaTime);

	// Rotate the earth.
	//earth_local_transform = rotation_matrix * earth_local_transform;
	earth_local_transform *= rotation_matrix;

	// Set earth orbit speed.
	rotation_matrix.setRotateZ(deltaTime * earth_orbit);
	earth_local_transform = rotation_matrix * earth_local_transform;

	// Calculate the global postion of the earth off the sun position.
	earth_world_transform = sun_world_transform * earth_local_transform;

	// Rotate the moon.
	rotation_matrix.setRotateZ(deltaTime * moon_rotation);
	moon_local_transform *= rotation_matrix;

	// Set moon rotate speed
	rotation_matrix.setRotateZ(-deltaTime * moon_orbit);
	moon_local_transform = rotation_matrix * moon_local_transform;


	// Calculate the global postion of the earth off the earth position.
	moon_world_transform = earth_world_transform * moon_local_transform;

	// Rotate the station.
	rotation_matrix.setRotateZ(-deltaTime * station_rotation * 0.5f);
	station_local_transform *= rotation_matrix;

	// Set station rotate speed
	rotation_matrix.setRotateZ(deltaTime * station_orbit);
	station_local_transform = rotation_matrix * station_local_transform;


	// Calculate the global postion of the moon off the moon position.
	station_world_transform = moon_world_transform * station_local_transform;



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

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawSpriteTransformed3x3(m_sun_texture, sun_world_transform, 100.0f, 100.0f);

	// Draw the sun.
	m_2dRenderer->drawSpriteTransformed3x3(m_sun_texture, sun_world_transform, 100.0f, 100.0f);

	// Draw the earth
	m_2dRenderer->drawSpriteTransformed3x3(m_earth_texture, earth_world_transform, 50.0f, 50.0f);

	// Draw the moon.
	m_2dRenderer->drawSpriteTransformed3x3(m_moon_texture, moon_world_transform, 20.0f, 20.0f);

	// Draw the station
	m_2dRenderer->drawSpriteTransformed3x3(m_station_texture, station_world_transform, 10.0f, 10.0f);
	

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