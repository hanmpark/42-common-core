/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:42:53 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:33:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy._type) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "[Cat] Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "[Cat] Meow meow" << std::endl;
}
