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

	m_font = new aie::Font("./font/consolas.ttf", 32);

	sun_world_transform.position = Vector3(640.0f, 340.0f, 1.0f);
	earth_local_transform.position = Vector3(0.0f, 200.0f, 1.0f);
	moon_local_transform.position = Vector3(0.0f, 70.0f, 1.0f);

	
	m_timer = 0;

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

	Matrix3 rotation;

	rotation.setRotateZ(deltaTime);

	// Rotates object by this rotation matrix.
	sun_world_transform *= rotation;

	// Ship spins same as parent.
	rotation.setRotateZ(deltaTime);

	// Rotate the earth.
	//earth_local_transform = rotation * earth_local_transform;
	earth_local_transform *= rotation;

	// Calculate the global postion of the earth off the sun position.
	earth_world_transform = sun_world_transform * earth_local_transform;

	// Rotate the moon.
	moon_local_transform *= rotation;

	// Calculate the global postion of the earth off the earth position.
	moon_world_transform = earth_world_transform * moon_local_transform;


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