/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:37:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/04 19:18:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
* Orthodox canonical form:
* - Default constructor
* - Copy constructor
* - Destructor
* - Copy assignment operator
*/

AAnimal::AAnimal() : _type("Some unknown Animal") {

	std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy) : _type(copy._type) {

	std::cout << "[AAnimal] Copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {

	std::cout << "[AAnimal] Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {

	std::cout << "[AAnimal] Copy assignment called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

// End of the orthodox canonical form

AAnimal::AAnimal(std::string type) : _type(type) {

	std::cout << "[AAnimal] String constructor called" << std::endl;
}

std::string const AAnimal::getType() const {

	return _type;
}
