/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:59:09 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/19 17:57:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

# define PURPLE	"\033[38;5;99m"
# define GREEN	"\033[38;5;115m"
# define BOLD	"\033[1m"
# define DEF	"\033[0m"

template<typename T>
class Array {
private:
	T				*_array;
	unsigned int	_n;

public:
	Array<T>() : _n(0) { _array = new T [0]; }
	Array<T>(Array<T> const &copy) { *this = copy; }
	~Array<T>() { delete [] _array; }
	Array<T>	&operator=(Array<T> const &rhs) {
		if (this != &rhs) {
			_n = rhs._n;
			delete [] _array;
			_array = new T[_n];
			for (unsigned int i = 0; i < _n; i++) {
				_array[i] = rhs._array[i];
			}
		}
		return *this;
	}
	Array<T>(unsigned int n) : _n(n) { _array = new T[_n](); }

	// Getters
	unsigned int const	 &size() const {
		return _n;
	}

	// Operator overload
	T	&operator[](unsigned int i) const {
		if (i >= _n)
			throw IndexOutOfBoundsException();
		return _array[i];
	}

	// Exception
	class IndexOutOfBoundsException : public std::exception {
	public:
		virtual char const	*what() const throw() {
			return "Index is out of bounds";
		}
	};
};

template<typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> array) {
	o << "-----------------------------------" << std::endl;
	o << "Array length: " << array.size() << std::endl;
	o << (array.size() != 0 ? "Array content:" : "Empty array") << std::endl;
	for (unsigned int i = 0; i < array.size(); i++) {
		o << "[" << i << "] " << array[i] << std::endl;
	}
	o << "-----------------------------------";
	return o;
}

#endif
