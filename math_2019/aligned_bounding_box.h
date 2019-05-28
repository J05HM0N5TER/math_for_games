#pragma once
#ifndef ALIGHENED_BOUNDING_BOX_H
#define ALIGHENED_BOUNDING_BOX_H


#include "Vector2.h"
#include "Collider.h"
class aligned_bounding_box : public Collider
{
public:

	static const Vector2 DEFAULT_EXTENTS;

	aligned_bounding_box(const Vector2 & a_position = Vector2(),
		const Vector2 & a_extents = DEFAULT_EXTENTS);

	const Vector2 get_position() const;
	void set_position(const Vector2 & a_position);

	const Vector2 get_extents() const;
	void set_extents(const Vector2 & a_extents);

	const float get_width() const;
	const float get_height() const;

	const Vector2 get_max() const;
	const Vector2 get_min() const;

private:
	Vector2 m_position;

	union
	{
		Vector2 m_extents;
		struct
		{
			float m_width;
			float m_height;
		};
	};
};

#endif // !ALIGHENED_BOUNDING_BOX_H
