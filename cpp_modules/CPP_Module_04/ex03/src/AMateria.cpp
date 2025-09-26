/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:55:25 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:49:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("* no type *") {
	std::cout << GREEN "[AMateria] " << _type << " has been created" DEF << std::endl;
}

AMateria::AMateria(AMateria const &copy) {
	*this = copy;
	std::cout << GREEN "[AMateria] " << _type << " has been created" DEF << std::endl;
}

AMateria::~AMateria() {
	std::cout << GREEN "[AMateria] " << _type << " destroyed" DEF << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs) {
	std::cout << "[AMateria] Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << GREEN "[AMateria] " << _type << " has been created" DEF << std::endl;
}

std::string const	&AMateria::getType() const { return _type; }

void	AMateria::use(ICharacter &target) {
	std::cout << BLUE "[AMateria] " << _type << " used on " << target.getName() << DEF << std::endl;
}
