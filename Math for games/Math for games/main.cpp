#include <iostream>

#include "Matrix3.h"
#include "Matrix4.h"

int main() {

	Matrix3 matrix
	{
		5.0f,4.0f,3.0f,
		7.0f,9.0f,10.0f,
		1.0f,2.0f,3.0f
	};

	Vector3 thingy(2.0f, 4.0f, 6.0f);

	Vector4 thingy2(2.0f, 2.0f, 2.0f, 2.0f);

	thingy2[1] = 5.0f;

	Vector3 answer = matrix * thingy;

	Matrix3 matrix_result = matrix * matrix;

	matrix[1];

	return 0;
}