#pragma once

#include "Matrix3.h"
#include "Application.h"
#include "Renderer2D.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Matrix3 sun_world_transform;
	Matrix3 earth_local_transform;
	Matrix3 earth_world_transform;

	Matrix3 moon_local_transform;
	Matrix3 moon_world_transform;

	// Plannet textures.
	aie::Texture*		m_earth_texture;
	aie::Texture*		m_sun_texture;
	aie::Texture*		m_moon_texture;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	float m_timer;
};