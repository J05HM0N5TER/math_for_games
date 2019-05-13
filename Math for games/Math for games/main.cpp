#include <iostream>
#include "Vector.h"


int main(void)
{
	Vector3<float> v;

	v.x = 2.0f;
	v.y = 2.0f;
	v.z = 1.0f;

	float* new_ptr = (float*)v;
	v.normalize();
	v.normalized();
	v.square_magnitude();
	v.magnitude();

	system("pause");
	return 0;
}