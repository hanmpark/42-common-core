/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:53:50 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:29:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(Fixed const &copy);
	Fixed	&operator=(Fixed const &rhs);
	~Fixed();

	Fixed(int const d);
	Fixed(float const f);

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;

	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;

	Fixed	operator++(int);
	Fixed	&operator++();
	Fixed	operator--(int);
	Fixed	&operator--();

	static Fixed		&min(Fixed &first, Fixed &second);
	static Fixed const	&min(Fixed const &first, Fixed const &second);
	static Fixed		&max(Fixed &first, Fixed &second);
	static Fixed const	&max(Fixed const &first, Fixed const &second);

private:
	int					_fixedPointValue;
	static int const	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fp);

#endif