#pragma once
#include "circle.h"
#include "aabb.h"
#include "line.h"
class collision_manager
{
public:

	static bool circle_to_circle(const circle & a_circle_A,
		const circle & a_circle_B);

	static bool aabb_to_aabb(const aabb & a_aabb_A,
		const aabb & a_aabb_B);

	static bool aabb_to_circle(const aabb & a_aabb,
		const circle & a_circle);

	static bool circle_to_line(const circle & a_circle,
		const line & a_line);

	static bool aabb_to_line(const aabb & a_aabb,
		const line & a_line);


private:
	static Vector2 clamp(const Vector2 & a_vector_2,
		const Vector2 & a_min,
		const Vector2 & a_max);
};

