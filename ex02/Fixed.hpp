#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		Fixed( const Fixed &copy );
		~Fixed();

		Fixed	&operator=( const Fixed &copy );
		Fixed	operator+( const Fixed &fixed ) const;
		Fixed	operator-( const Fixed &fixed ) const;
		Fixed	operator*( const Fixed &fixed ) const;
		Fixed	operator/( const Fixed &fixed ) const;
		Fixed	&operator++();
		Fixed	operator++( int );
		Fixed	&operator--();
		Fixed	operator--( int );
		
		bool	operator>( const Fixed &fixed ) const;
		bool	operator<( const Fixed &fixed ) const;
		bool	operator>=( const Fixed &fixed ) const;
		bool	operator<=( const Fixed &fixed ) const;
		bool	operator==( const Fixed &fixed ) const;
		bool	operator!=( const Fixed &fixed ) const;

		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );

		static const Fixed	&min( const Fixed &a, const Fixed &b );
		static const Fixed	&max( const Fixed &a, const Fixed &b );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<( std::ostream &out, const Fixed &fixed );

#endif