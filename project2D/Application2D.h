#pragma once

#include "Matrix3.h"
#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include "game_object.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	//Matrix3 sun_world_transform;
	//Matrix3 earth_local_transform;
	//Matrix3 earth_world_transform;
	//float earth_rotation;
	//float earth_orbit;

	//Matrix3 moon_local_transform;
	//Matrix3 moon_world_transform;
	//float moon_rotation;
	//float moon_orbit;

	game_object* sun;
	game_object* earth;
	game_object* moon;
	game_object* station;
	game_object* mars;
	game_object* jupiter;
	game_object* saturn;
	game_object* mercury;
	game_object* venus;
	game_object* uranus;

	//Matrix3 station_local_transform;
	//Matrix3 station_world_transform;
	//float station_rotation;
	//float station_orbit;

	// Plannet textures.
	aie::Texture*		m_mars_texture;
	aie::Texture*		m_uranus_texture;
	aie::Texture*		m_jupiter_texture;
	aie::Texture*		m_mercury_texture;
	aie::Texture*		m_venus_texture;
	aie::Texture*		m_saturn_texture;
	aie::Texture*		m_earth_texture;
	aie::Texture*		m_sun_texture;
	aie::Texture*		m_moon_texture;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	float m_timer;
};