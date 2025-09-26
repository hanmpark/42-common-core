/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:20:17 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:38:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy._type) {
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "[WrongCat] Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "[WrongCat] Meow meow" << std::endl;
}
