#include <iostream>
#include "Vector.h"

int main(void)
{
	Vector2<float> v;

	v.x = 2.0f;
	v.y = 2.0f;


	v.square_magnitude();

	system("pause");
	return 0;
}