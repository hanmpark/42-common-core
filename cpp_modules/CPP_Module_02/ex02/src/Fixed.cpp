/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:54:08 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:17:55 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
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

int	Fixed::getRawBits() const {
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

float	Fixed::toFloat() const {
	return static_cast<float>(getRawBits()) / (1 << _fractionalBits);
}

int	Fixed::toInt() const {
	return getRawBits() / (1 << _fractionalBits);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second) {
	if (first < second) {
		return first;
	}
	return second;
}

Fixed const	&Fixed::min(Fixed const &first, Fixed const &second) {
	if (first < second) {
		return first;
	}
	return second;
}

Fixed	&Fixed::max(Fixed &first, Fixed &second) {
	if (first > second) {
		return first;
	}
	return second;
}

Fixed const	&Fixed::max(Fixed const &first, Fixed const &second) {
	if (first > second) {
		return first;
	}
	return second;
}

bool	Fixed::operator>(Fixed const &rhs) const {
	return getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const &rhs) const {
	return getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	return getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	return getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const &rhs) const {
	return getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	return getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &rhs) const {
	Fixed sum(toFloat() + rhs.toFloat());

	return sum;
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	Fixed difference(toFloat() - rhs.toFloat());

	return difference;
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	Fixed product(toFloat() * rhs.toFloat());

	return product;
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	Fixed quotient(toFloat() / rhs.toFloat());

	return quotient;
}

Fixed	Fixed::operator++(int) {
	Fixed postIncrement(*this);

	postIncrement._fixedPointValue = _fixedPointValue++;

	return postIncrement;
}

Fixed	&Fixed::operator++() {
	_fixedPointValue++;

	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed postDecrement(*this);

	postDecrement._fixedPointValue = _fixedPointValue--;

	return postDecrement;
}

Fixed	&Fixed::operator--() {
	_fixedPointValue--;

	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fp) {
	o << fp.toFloat();

	return o;
}
