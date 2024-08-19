#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(1, 1);

    if (bsp(a, b, c, point)) {
        std::cout << "Point is inside the triangle.\n";
    } else {
        std::cout << "Point is outside the triangle.\n";
    }

    return 0;
}
