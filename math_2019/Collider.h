#pragma once
class Collider
{
public:
	// Disable default constructor.
	Collider() = delete;

	enum class shape : char
	{
		none = 0,
		circle,
		aabb,
		line,
	};

	const shape get_shape() const;

protected:

	shape m_shape = shape::none;
	Collider(shape a_shape);
};

