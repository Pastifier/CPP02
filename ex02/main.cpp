#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	union {
		__uint32_t repI;
		float	   repF;
	}	bitField;
	bitField.repI = 0x7f800000l;
	try {
	Fixed const f(Fixed(bitField.repF));
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << Fixed::max(0x7f800000, b) << std::endl;

	for (int i = 0; i < 100; i++) {
		a++;
	}

	std::cout << a << std::endl;
	
	return 0;
}
