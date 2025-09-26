/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:37:04 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:33:12 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal") {
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(Animal const &copy) : _type(copy._type) {
	std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs) {
	std::cout << "[Animal] Copy assignment called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[Animal] String constructor called" << std::endl;
}

std::string const	Animal::getType() const { return _type; }

void	Animal::makeSound() const {
	std::cout << "[Animal] * making weird animal noises *" << std::endl;
}
