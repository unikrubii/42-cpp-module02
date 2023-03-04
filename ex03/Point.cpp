#include "Point.hpp"

Point::Point() {
	this->_x = 0;
	this->_y = 0;
}

Point::Point( const float x, const float y ) {
	this->_x = x;
	this->_y = y;
}

Point::Point( const Point &copy ) {
	*this = copy;
}

Point::~Point() {
}

Point &Point::operator=( const Point &copy ) {
	this->_x = copy.getX();
	this->_y = copy.getY();
	return *this;
}

float	Point::getX( void ) const {
	return this->_x;
}

float	Point::getY( void ) const {
	return this->_y;
}
