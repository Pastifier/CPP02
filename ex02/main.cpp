#include "Fixed.hpp"

#define __USR_DEF_CONST 5

int main(void) {
	std::cout << "---------------------------------- INITIALISING TWO VARIABLES TO TEST WITH ----------------------------------" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(-1);
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;
	
	std::cout << "----------------- TESTING POST-{INCREMENT/DECREMENT}, PRE-{INCREMENT/DECREMENT} -----------------------------" << std::endl;
	std::cout << a /* / 0 */<< std::endl;
	std::cout << ++a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a-- << std::endl;
	
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;

	std::cout << "------------------------------------------ Now we're talking. :3 --------------------------------------------" << std::endl;
	union {
		__uint32_t repI;
		float	   repF;
	}	bitField;
	bitField.repI = 0x7f800000;
	try {
	Fixed const f(Fixed(bitField.repF));
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;

	std::cout << "---------------------------------- MIN/MAX STATIC METHODS TESTING -------------------------------------------" << std::endl;
	std::cout << Fixed::max(0x7f800000, b) << std::endl;
	std::cout << Fixed::min(b, 0x7f800000) << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;

	std::cout << "---------------------------------- CHECKING COMPARISON BINARY OPERATIONS ------------------------------------" << std::endl;
	for (int i = 0; i < __USR_DEF_CONST; i++) {
		a++;
		if (a < __USR_DEF_CONST)
			std::cout << a << " is less than " << __USR_DEF_CONST << std::endl;
		if (a > __USR_DEF_CONST)
			std::cout << a << " is greater than " << __USR_DEF_CONST << std::endl;
		if (a <= __USR_DEF_CONST)
			std::cout << a << " is less than or eq to " << __USR_DEF_CONST << std::endl;
		if (a >= __USR_DEF_CONST)
			std::cout << a << " is greater than or eq to " << __USR_DEF_CONST << std::endl;
		if (a == __USR_DEF_CONST)
			std::cout << a << " is eq to " << __USR_DEF_CONST << std::endl;
		if (a != __USR_DEF_CONST)
			std::cout << a << " is not eq to " << __USR_DEF_CONST << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;

	std::cout << "---------------------------------- ADD/SUB BINARY OPERATIONS ------------------------------------------------" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b - a << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;
	
	return 0;
}
