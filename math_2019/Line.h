#pragma once
#ifndef LINE_H
#define LINE_H

#include "Collider.h"
#include "Vector2.h"
class Line :
	public Collider
{
public:

	static const Vector2 DEFAULT_NORMAL;

	Line(const Vector2 & a_normal = { 1.0f, 1.0f },
		const float a_distance = 0.0f);

	const Vector2 get_normal() const;
	void set_normal(const Vector2 & a_normal);

	const float get_distance() const;
	void set_distance(const float a_distance);

private:
	Vector2 m_normal = DEFAULT_NORMAL;
	float m_distance = 0.0f;

};

#endif // !LINE_H
