#include "unittest.h"
#include <iostream>

#include "Matrix3.h"

int main() {

	/*
	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;
	*/

	Matrix3 matrix
	{
		10.0f, 2.0f, 6.0f,
		5.0f, 7.0f, 8.0f,
		1.0f, 2.0f, 3.0f
	};

	Matrix3 matrix_result = matrix * matrix;

	matrix[1];

	return 0;
}