/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:25 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:33:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static void	putSeparator() {
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

static void	Animals() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "j is a " << j->getType() << std::endl;
	std::cout << "i is a " << i->getType() << std::endl;
	std::cout << "meta is an " << meta->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Their sound:" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
}

static void	WrongAnimals() {
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta is a " << wrongAnimal->getType() << std::endl;
	std::cout << "cat is a " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Their sound:" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;
}

int	main() {
	Animals();
	putSeparator();
	WrongAnimals();
	return 0;
}
