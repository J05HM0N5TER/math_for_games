#include <iostream>
#include "Vector3.h"


int main(void)
{
	Vector3<float> v1;
	Vector3<float> v2;

	v2.x = 0.70701f;
	v2.y = 0.70701f;
	v2.z = 0.0f;

	v1.x = 0.0f;
	v1.y = 0.0f;
	v1.z = 1.0f;

	v1.normalize();
	v2.normalize();

	Vector3<float> crossproduct = Vector3<float>::cross(v1, v2);

	float dot_product = Vector3<float>::dot(v1, v2);

	float* new_ptr = (float*)v1;
	v1.normalize();
	v1.normalized();
	v1.square_magnitude();
	v1.magnitude();

	system("pause");
	return 0;
}