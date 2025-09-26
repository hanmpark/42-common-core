/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:25 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:37:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j; // should not create a leak
	delete i;

	std::cout << std::endl;
	Animal* animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

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

	return (0);
}
