#pragma once

#include "Matrix3.h"
#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include "Input.h"
#include "game_object.h"
#include "player.h"

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
	game_object* sun;
	game_object* earth;
	game_object* moon;
	game_object* mars;
	game_object* jupiter;
	game_object* saturn;
	game_object* mercury;
	game_object* venus;
	game_object* uranus;

	std::vector<game_object*> planets;

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
	player* m_player;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Input* input;

	float m_timer;
};