#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>

class Point
{
	private:
		float _x;
		float _y;

	public:
		Point();
		Point( const float x, const float y );
		Point( const Point &copy );
		~Point();

		Point	&operator=( const Point &copy );

		float	getX( void ) const;
		float	getY( void ) const;
};

#endif