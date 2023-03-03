#include "Fixed.hpp"

Fixed::Fixed() {
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const int value ): _fixedPointValue(value << this->_fractionalBits) {
}

Fixed::Fixed( const float value ): _fixedPointValue(roundf(value * (1 << this->_fractionalBits))) {
}

Fixed::Fixed( const Fixed &copy ) {
	*this = copy;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=( const Fixed &copy ) {
	this->_fixedPointValue = copy.getRawBits();
	return *this;
}

Fixed Fixed::operator+( const Fixed &fixed ) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-( const Fixed &fixed ) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*( const Fixed &fixed ) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/( const Fixed &fixed ) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed copy(*this);
	this->_fixedPointValue++;
	return copy;
}

Fixed &Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed copy(*this);
	this->_fixedPointValue--;
	return copy;
}

bool Fixed::operator>( const Fixed &fixed ) const {
	return this->_fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<( const Fixed &fixed ) const {
	return this->_fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=( const Fixed &fixed ) const {
	return this->_fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=( const Fixed &fixed ) const {
	return this->_fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==( const Fixed &fixed ) const {
	return this->_fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=( const Fixed &fixed ) const {
	return this->_fixedPointValue != fixed.getRawBits();
}

Fixed &Fixed::min( Fixed &a, Fixed &b ) {
	return a < b ? a : b;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	return a > b ? a : b;
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
	return a < b ? a : b;
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
	return a > b ? a : b;
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
