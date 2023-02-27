#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const int value ): _fixedPointValue(value << this->_fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ): _fixedPointValue(roundf(value * (1 << this->_fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &copy ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream &operator<<( std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return out;
}
