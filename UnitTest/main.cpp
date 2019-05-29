#include "unittest.h"
#include <iostream>

#include"Collision_manager.h"
#include "Circle.h"
#include "aabb.h"

int main()
{
	aabb A{ {5.0f, 3.0f}, {2.0f, 2.0f} };
	aabb B{ {1.5f, 5.0f}, {3.0f, 2.0f} };
	aabb C{ {3.5f, 5.0f}, {3.0f, 6.0f} };

	// Works.
	std::cout << "aabb to aabb\n";
	std::cout << collision_manager::aabb_to_aabb(A, B) << '\t';
	std::cout << collision_manager::aabb_to_aabb(B, A) << '\t';
	std::cout << "\t Expected 0\n";

	std::cout << collision_manager::aabb_to_aabb(A, C) << '\t';
	std::cout << collision_manager::aabb_to_aabb(C, A) << '\t';
	std::cout << "\t Expected 1\n";

	std::cout << collision_manager::aabb_to_aabb(C, B) << '\t';
	std::cout << collision_manager::aabb_to_aabb(B, C) << '\t';
	std::cout << "\t Expected 1\n";

	circle circle_A{ {2.0f, 9.0f}, 1.5f };
	circle circle_B{ {2.0f, 11.0f}, 1.5f };
	circle circle_C{ {5.0f, 9.0f}, 1.5f };

	// Works
	std::cout << "\ncircle to circle\n";
	std::cout << collision_manager::circle_to_circle(circle_A, circle_B) << '\t';
	std::cout << collision_manager::circle_to_circle(circle_B, circle_A) << '\t';
	std::cout << "\t Expected 1\n";

	std::cout << collision_manager::circle_to_circle(circle_A, circle_C) << '\t';
	std::cout << collision_manager::circle_to_circle(circle_C, circle_A) << '\t';
	std::cout << "\t Expected 0\n";

	std::cout << collision_manager::circle_to_circle(circle_C, circle_B) << '\t';
	std::cout << collision_manager::circle_to_circle(circle_B, circle_C) << '\t';
	std::cout << "\t Expected 0\n";

	// Work
	std::cout << "\naabb to circle\n";
	std::cout << collision_manager::aabb_to_circle(C, circle_A) << '\t';
	std::cout << "\t Expected 1\n";
	std::cout << collision_manager::aabb_to_circle(C, circle_B) << '\t';
	std::cout << "\t Expected 0\n";

	std::cout << collision_manager::aabb_to_circle(B, circle_A) << '\t';
	std::cout << "\t Expected 0\n";
	std::cout << collision_manager::aabb_to_circle(B, circle_B) << '\t';
	std::cout << "\t Expected 0\n";


	circle unit_circle{ Vector2(), 1.0f };
	circle up_circle{ {0.0f, 5.0f}, 1.0f };

	line its_a_line{ /*{1, 0}*/line::DEFAULT_NORMAL, 3.0f };

	// Work.
	std::cout << "\ncircle to line\n";
	std::cout << collision_manager::circle_to_line(unit_circle, its_a_line);
	std::cout << "\t Expected 1\n";
	std::cout << collision_manager::circle_to_line(up_circle, its_a_line);
	std::cout << "\t Expected 0\n";

	// Doesn't work
	std::cout << "\nAABB to Line\n";
	std::cout << collision_manager::aabb_to_line(A, its_a_line);
	std::cout << "\t Expected 0\n";
	std::cout << collision_manager::aabb_to_line(B, its_a_line);
	std::cout << "\t Expected 0\n";
	std::cout << collision_manager::aabb_to_line(C, its_a_line);
	std::cout << "\t Expected 1\n";

	//if (runUnitTests() == false) {
	//	std::cout << "Unit test failed!" << std::endl;
	//	system("pause");
	//	return -1;
	//}
	//std::cout << "All tests passed successfully." << std::endl;



	system("pause");
	return 0;
}