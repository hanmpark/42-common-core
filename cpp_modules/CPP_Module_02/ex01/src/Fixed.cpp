/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:54:08 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:16:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const d) : _fixedPointValue(d * (1 << _fractionalBits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = rhs.getRawBits();

	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const { return _fixedPointValue; }

void	Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

float	Fixed::toFloat(void) const { return static_cast<float>(getRawBits()) / (1 << _fractionalBits); }

int	Fixed::toInt(void) const { return getRawBits() / (1 << _fractionalBits); }

std::ostream	&operator<<(std::ostream &o, Fixed const &fp) {
	o << fp.toFloat();
	return o;
}
