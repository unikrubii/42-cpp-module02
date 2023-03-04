#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main( void ) {
	Point a(0.0, 0.0);
	Point b(5.0, 0.0);
	Point c(0.0, 4.0);

	Point inside(2.0, 2.0);
	Point outside(5.0, 5.0);
	Point edge1(0.0, 1.0);
	Point edge2(5.0, 0.0);

	std::cout << "Inside " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside " << bsp(a, b, c, outside) << std::endl;
	std::cout << "edge1 " <<  bsp(a, b, c, edge1) << std::endl;
	std::cout << "edge2 " <<  bsp(a, b, c, edge2) << std::endl;
	return (0);
}