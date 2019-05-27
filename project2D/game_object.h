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

	// \brief Updates the position for the game_object.
	void update(const float a_delta_time);

	// \brief Draws the object on screen.
	void draw();

	// \brief Returns the world position of the object.
	const Matrix3& get_world_matrix() const;
	const Vector2& get_postion() const;

	//void set_position(const Vector2& a_position);
	void set_local_position(const Vector2& a_position);

	//void set_rotation(const float& a_position);
	// \brief Gets the rotation of the object with the transforms of the parents into account.
	const float& get_global_rotation() const;
	// \brief Sets the rotation that doesn't get affected by the transforms of the parent objects.
	void set_global_rotation(const float& a_rotaion_speed);
	// \brief Sets the orbit speed that doesn't get affected by the transforms of the parent objects.
	void set_global_orbit(const float& a_orbit_speed);

	// \brief Set the local orbit speed.
	void set_orbit_speed(const float& a_orbit_speed);
	// \brief Get the local orbit speed.
	const float& get_orbit_speed() const;

	// \brief Gets the local rotation speed.
	const float& get_rotation_speed() const;

	// \brief Sets the parent for the object.
	void set_parent(game_object* a_parent);
	// \brief Gets a pointer to the parent.
	game_object* get_parent() const;

	// \brief Sets the display size of the object.
	void set_size(const Vector2& a_size);
	// \brief Gets the display size of the object.
	const Vector2& get_size() const;

private:

	// \brief Added a child to the object.
	void add_child(game_object* a_child);

	// The transform that has all the parents transforms taken into account.
	Matrix3 m_world_transform;
	// The transform that has not taken all the parents transforms into account.
	Matrix3 m_local_transform;

	// How quick the object orbits the parent in radians per second.
	float m_orbit_speed;
	// How quick the object rotates in radians per second.
	float m_rotation_speed;

	// What the object is being drawn as.
	aie::Texture* m_texture;

	// The pointer to the renderer so it can draw itself.
	aie::Renderer2D* m_renderer;

	// The size the object will be displayed at.
	Vector2 m_size;

	// The difference in position between the parent and this object.
	Vector2 m_position;
	// The current local rotation.
	float m_current_rotation;

	// The parent that this object has to take into account when creating the world_transform.
	game_object* m_parent;

	// A vector of all the object that are using this objects transform in there calculations for there world_transform.
	std::vector<game_object*> m_children;
};

#endif // !GAME_OBJECT_H
