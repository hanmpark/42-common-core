/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:49:49 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/22 08:43:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical form

Span::Span(size_t N) : _N(N) {
	_vec.reserve(_N);
}

Span::Span(Span const &copy) {
	*this = copy;
}

Span::~Span() {}

Span	&Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		_vec.resize(_N);
	}
	return *this;
}
// Getter

std::vector<int> const	&Span::getVec() const {
	return _vec;
}

// Methods

void	Span::addNumber(unsigned int number) {
	if (_vec.size() >= _N)
		throw OutOfBoundsException();
	_vec.push_back(number);
}

void	Span::addNumber(std::vector<int>::const_iterator it, std::vector<int>::const_iterator it2) {
	if (_vec.size() >= _N)
		throw OutOfBoundsException();
	_vec.insert(_vec.end(), it, it2);
}

unsigned int	Span::shortestSpan() const {
	if (_vec.size() < 2)
		throw NoSpanException();

	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	it2;
	int									distance;
	unsigned int						minDistance = longestSpan();

	for (it = _vec.begin(); it != _vec.end(); it++) {
		for (it2 = _vec.begin(); it2 != _vec.end(); it2++) {
			if (it != it2) {
				distance = std::abs(*it - *it2);
				if (distance < static_cast<int>(minDistance))
					minDistance = static_cast<unsigned int>(distance);
			}
		}
	}
	return minDistance;
}

unsigned int	Span::longestSpan() const {
	if (_vec.size() < 2)
		throw NoSpanException();

	unsigned int	maxDistance =	*std::max_element(_vec.begin(), _vec.end()) \
									- *std::min_element(_vec.begin(), _vec.end());
	return maxDistance;
}

// Exceptions
char const	*Span::OutOfBoundsException::what() const throw() {
	return "Out of bounds";
}

char const	*Span::NoSpanException::what() const throw() {
	return "Cannot calculate span, Vector's size is too small";
}

// Operator overload
std::ostream	&operator<<(std::ostream &o, Span &sp) {
	o << "-------------------------------------" << std::endl;
	std::vector<int>::const_iterator	it;
	for (it = sp.getVec().begin(); it != sp.getVec().end(); it++) {
		o << *it << (it + 1 != sp.getVec().end() ? " " : "");
	}
	o << std::endl << "-------------------------------------";
	return o;
}
