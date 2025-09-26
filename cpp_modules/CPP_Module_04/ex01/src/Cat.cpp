/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:42:53 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:36:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Default constructor called" << std::endl;
	_brain = new Brain("cat");
}

Cat::Cat(Cat const &copy) : Animal(copy._type) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
	delete _brain;
}

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "[Cat] Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		_type = rhs._type;
		*_brain = *rhs._brain;
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "[Cat] Meow meow" << std::endl;
}

void	Cat::telepathy(int nbr) const {
	_brain->sayIdeas(nbr);
}
