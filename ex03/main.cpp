#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(1, 1);

    Fixed d = 1;
    Fixed e = 0;

    try {
        std::cout << d / e << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    if (bsp(a, b, c, point)) {
        std::cout << "Point is inside the triangle.\n";
    } else {
        std::cout << "Point is outside the triangle.\n";
    }

    return 0;
}
