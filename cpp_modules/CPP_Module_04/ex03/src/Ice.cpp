/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:37:13 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:48:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &copy) : AMateria("ice") {
	*this = copy;
}

Ice::~Ice() {}

Ice	&Ice::operator=(Ice const &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

AMateria	*Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
	std::cout << BLUE "* shoots an ice bolt at " << target.getName() << " *" << DEF << std::endl;
}
