/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:05:07 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:33:28 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy._type) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs) {
	std::cout << "[Dog] Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "[Dog] Waf waf" << std::endl;
}
