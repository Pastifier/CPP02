#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(1, 1);

    std::cout << "\n------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;   
    std::cout << "For vertices { (0,0) , (5,0) , (0,5) }: \n" << std::endl;
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;
    if (bsp(a, b, c, point)) {
        std::cout << "Point (1,1) is inside the triangle.\n";
    } else {
        std::cout << "Point (1,1) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(100, 100))) {
        std::cout << "Point (100,100) is inside the triangle.\n";
    } else {
        std::cout << "Point (100,100) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(0, 5))) {
        std::cout << "Point (0,5) is inside the triangle.\n";
    } else {
        std::cout << "Point (0,5) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(5, 0))) {
        std::cout << "Point (5,0) is inside the triangle.\n";
    } else {
        std::cout << "Point (5,0) is outside the triangle.\n";
    }
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;

    a = Point(-2, -15);
    b = Point(-15, -2);
    c = Point(0, 0);
    std::cout << "For vertices { (-2,-15) , (-15,-2) , (0,0) }: \n" << std::endl;
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;
    if (bsp(a, b, c, point)) {
        std::cout << "Point (1,1) is inside the triangle.\n";
    } else {
        std::cout << "Point (1,1) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(0, -1))) {
        std::cout << "Point (0,-1) is inside the triangle.\n";
    } else {
        std::cout << "Point (0,-1) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(-500, 5))) {
        std::cout << "Point (-500,5) is inside the triangle.\n";
    } else {
        std::cout << "Point (-500,5) is outside the triangle.\n";
    }

    if (bsp(a, b, c, Point(-12, -13))) {
        std::cout << "Point (-12, -13) is inside the triangle.\n";
    } else {
        std::cout << "Point (-12, -13) is outside the triangle.\n";
    }
    std::cout << "------ - - -- - ---- -- --- - -- --- -- \n" << std::endl;
    
    return 0;
}
