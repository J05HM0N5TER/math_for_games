#pragma once

#include "Vector3.h"
#include "Application.h"
#include "Renderer2D.h"

class SolarSystemApp : public aie::Application {
public:

	SolarSystemApp();
	virtual ~SolarSystemApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};