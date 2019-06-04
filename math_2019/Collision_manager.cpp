#include "collision_manager.h"
#include <cmath>

bool collision_manager::circle_to_circle(const circle & a_circle_A, const circle & a_circle_B)
{
	Vector2 dispacement = (a_circle_A.get_position() - a_circle_B.get_position());
	float sum_of_radii = a_circle_A.get_radus() + a_circle_B.get_radus();

	return (dispacement.magnitude() < sum_of_radii);
}

bool collision_manager::aabb_to_aabb(const aabb & a_aabb_A, const aabb & a_aabb_B)
{
	return !(a_aabb_A.get_max().x < a_aabb_B.get_min().x ||
			 a_aabb_A.get_min().x > a_aabb_B.get_max().x ||
			 a_aabb_A.get_max().y < a_aabb_B.get_min().y ||
			 a_aabb_A.get_min().y > a_aabb_B.get_max().y);
}

bool collision_manager::aabb_to_circle(const aabb & a_aabb, const circle & a_circle)
{
	Vector2 clamped_center = clamp(a_circle.get_position(), a_aabb.get_min(), a_aabb.get_max());
	Vector2 displacement = clamped_center - a_circle.get_position();

	return (displacement.magnitude() < a_circle.get_radus());
}

bool collision_manager::circle_to_line(const circle & a_circle, 
	const line & a_line)
{
	float position_dot_normal = (a_circle.get_position().dot(a_line.get_normal()));
	float distance = position_dot_normal -
		(a_line.get_distance() + a_circle.get_radus());

	return (distance < 0);
}

bool collision_manager::aabb_to_line(const aabb & a_aabb, const line & a_line)
{
	// #1 kiio eacg cirber abd /*Typing is hard?*/ bit product the distance
	//		then the furthest negative distance is the corner of the gratest overlap.
	//float position_dot_normal = (a_aabb.get_max().dot(a_line.get_normal()));
	//float distance = position_dot_normal - a_line.get_distance();

	Vector2 extents = 0.5f * a_aabb.get_extents();
	Vector2 extents_neg_x = Vector2(-a_aabb.get_extents().x, a_aabb.get_extents().y);

	float dot_extents = extents.dot(a_line.get_normal());
	float dot_extents_neg_x = extents_neg_x.dot(a_line.get_normal());

	float radus = fmaxf(fabs(dot_extents), fabs(dot_extents_neg_x));

	circle projection{ a_aabb.get_position(), radus };

	return circle_to_line(projection, a_line);
}

Vector2 collision_manager::clamp(const Vector2 & a_vector_2, const Vector2 & a_min, const Vector2 & a_max)
{
	return
	{
		fminf(fmaxf(a_vector_2.x, a_min.x), a_max.x),
		fminf(fmaxf(a_vector_2.y, a_min.y), a_max.y)
	};
}
