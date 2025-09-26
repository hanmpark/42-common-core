/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:25 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:48:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static void putSeparator() {
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

static void Animals() {
	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	std::cout << std::endl;
	std::cout << "j is a " << j->getType() << std::endl;
	std::cout << "i is a " << i->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Their sound:" << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;

	delete j;
	delete i;
}

static void WrongAnimals() {
	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

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

int main() {
	Animals();
	putSeparator();
	WrongAnimals();

	std::cout << std::endl;

	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	delete j; // should not create a leak
	delete i;

	std::cout << std::endl;
	AAnimal*	animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
		delete animals[i];
		animals[i] = NULL;
	}

	std::cout << std::endl;
	Dog tmp;
	{
		Dog copy = tmp;
		copy.getType();
		copy.makeSound();
		copy.telepathy(3);
	}
	std::cout << std::endl;
	return 0;
}
