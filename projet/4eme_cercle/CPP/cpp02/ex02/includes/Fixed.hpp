#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int					_value;
        static const int	fractional_bits = 8;
	public :
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &cpy);
		Fixed &operator=(const Fixed &other);
		~Fixed();

				/* Opérateurs de comparaison */
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

				/* Opérateurs arithmétiques */
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

				/* Incrément / décrément */
		Fixed	&operator++(void);	// ++a
		Fixed	operator++(int);	// a++
		Fixed	&operator--(void);	// --a
		Fixed	operator--(int);	// a--

				/* Fonctions statiques min / max */
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
