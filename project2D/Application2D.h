#pragma once

#include "Matrix3.h"
#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include "Input.h"
#include "game_object.h"

class Application2D : public aie::Application 
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	// Planets
	game_object* m_sun;
	game_object* m_earth;
	game_object* m_moon;
	game_object* m_mars;
	game_object* m_jupiter;
	game_object* m_saturn;
	game_object* m_mercury;
	game_object* m_venus;
	game_object* m_uranus;

	std::vector<game_object*> m_planets;

	// Planet textures.
	aie::Texture*		m_mars_texture;
	aie::Texture*		m_uranus_texture;
	aie::Texture*		m_jupiter_texture;
	aie::Texture*		m_mercury_texture;
	aie::Texture*		m_venus_texture;
	aie::Texture*		m_saturn_texture;
	aie::Texture*		m_earth_texture;
	aie::Texture*		m_sun_texture;
	aie::Texture*		m_moon_texture;

	// ship
	aie::Texture*		m_player_texture;
	game_object* m_player;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Input* input;

	float m_timer;
};