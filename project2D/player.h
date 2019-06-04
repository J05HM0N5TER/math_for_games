#pragma once
#include"Circle.h"
#include "Vector2.h"
#include "game_object.h"
#include "Input.h"

class player : public game_object
{
public:
	player() = delete;
	player(aie::Renderer2D* a_renderer, aie::Texture* a_texture, aie::Input* a_input, const Vector2 a_position);
	~player();

	void update(const float a_delta_time) override;

	// If the player is still alive.
	bool is_valid;
private:

	aie::Input* m_input;

};

