/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:53:09 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:48:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &copy) : AMateria("cure") {
	*this = copy;
}

Cure::~Cure() {

}

Cure	&Cure::operator=(Cure const &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

AMateria	*Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
	std::cout << BLUE "* heals " << target.getName() << "'s wounds *" DEF << std::endl;
}
