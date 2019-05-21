#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Matrix3.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include "Texture.h"
#include <vector>

class game_object
{
public:
	game_object(aie::Renderer2D* a_renderer, aie::Texture* a_texture, const Vector2 a_position, const float a_z_rotation, 
		const Vector2 a_size = { 0.0f, 0.0f }, const float a_spin_speed = 0.0f, const float a_orbit_speed = 0.0f);
	~game_object();

	void update(const float a_delta_time);

	void draw();


	const Matrix3& get_world_matrix() const;
	const Vector2& get_postion() const;

	//void set_position(const Vector2& a_position);
	void set_local_position(const Vector2& a_position);

	//void set_rotation(const float& a_position);
	//void set_global_rotation(const float& a_position);

	void set_parent(game_object* a_parent);

	void add_child(game_object* a_child);

//private:
	Matrix3 m_world_transform;
	Matrix3 m_local_transform;

	// How quick the object orbits the perent in radians per second.
	float m_orbit_speed;
	// How quick the object rotates in radians per second.
	float m_rotation_speed;

	// What the object is being drawn as.
	aie::Texture* m_texture;

	// The pointer to the renderer so it can draw itself.
	aie::Renderer2D* m_renderer;

	// The size the object will be displayed at.
	Vector2 m_size;

	// The difference in position between the perent and this object.
	Vector2 m_position;
	float m_current_rotation;

	game_object* m_parent;

	std::vector<game_object*> m_children;
};

#endif // !GAME_OBJECT_H
