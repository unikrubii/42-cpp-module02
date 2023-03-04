// area of triangle (1 / 2) |[x1 (y2 – y3 ) + x2 (y3 – y1 ) + x3(y1 – y2)]|

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	computeArea( const Point &a, const Point &b, const Point &c ) {
	Fixed x1( a.getX() );
	Fixed y1( a.getY() );
	Fixed x2( b.getX() );
	Fixed y2( b.getY() );
	Fixed x3( c.getX() );
	Fixed y3( c.getY() );
	Fixed area = ( x1 * ( y2 - y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1 - y2 ) ) / 2;
	if ( area < 0) 
		area = area * Fixed( -1 );
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed area = computeArea( a, b, c );
	Fixed area1 = computeArea( point, b, c );
	Fixed area2 = computeArea( a, point, c );
	Fixed area3 = computeArea( a, b, point );

	return area == area1 + area2 + area3 && area1 != 0 && area2 != 0 && area3 != 0;
}
