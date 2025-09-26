/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:11:36 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:49:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
	std::cout << GREEN "[MateriaSource] has been created" DEF << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
	*this = copy;
	std::cout << GREEN "[MateriaSource] has been created" DEF << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i]) {
			delete _materias[i];
		}
		_materias[i] = NULL;
	}
	std::cout << GREEN "[MateriaSource] has been destroyed" DEF << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			_materias[i] = rhs._materias[i];
		}
	}
	return *this;
}

AMateria	*MateriaSource::getMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i];
		}
	}
	return NULL;
}

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL) {
			_materias[i] = m;
			return;
		}
	}
	delete m;
	m = NULL;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return NULL;
}
