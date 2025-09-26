/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:07 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:49:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main() {
	IMateriaSource *src = new MateriaSource();

	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	ICharacter	*me = new Character("me");

	std::cout << std::endl;
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->unequip(2);
	me->unequip(3);
	me->unequip(2);

	me->checkground();

	std::cout << std::endl;
	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}
