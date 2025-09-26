/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:54:08 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:20:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
}

Fixed::Fixed(int const d) : _fixedPointValue(d * (1 << _fractionalBits)) {}

Fixed::Fixed(float const f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {}

Fixed	&Fixed::operator=(Fixed const &rhs) {
	_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int	Fixed::getRawBits() const { return _fixedPointValue; }

void	Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

float	Fixed::toFloat() const { return static_cast<float>(getRawBits()) / (1 << _fractionalBits); }

int	Fixed::toInt() const { return getRawBits() / (1 << _fractionalBits); }

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

/* ************************************************************************** */
/*                              Operator overloads                            */
/* ************************************************************************** */

/* ******************************* Comparison ******************************* */

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

/* ************************** Increment / Decrement ************************* */

Fixed	Fixed::operator+(Fixed const &rhs) const {
	return Fixed(toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	return Fixed(toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	return Fixed(toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	return Fixed(toFloat() / rhs.toFloat());
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
