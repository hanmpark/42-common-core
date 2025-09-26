/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:52:09 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:40:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] Default constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "[Brain] Copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs) {
	std::cout << "[Brain] Copy assignment called" << std::endl;

	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

Brain::Brain(std::string const &animalType) {
	std::cout << "[Brain] has been created" << std::endl;
	if (animalType == "cat") {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = "Annoy hooman";
		}
	} else if (animalType == "dog") {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = "Bark bark";
		}
	} else {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = "...";
		}
	}
}

void	Brain::sayIdeas(int nbr) const {
	for (int i = 0; i < nbr && i < 100; i++) {
		std::cout << _ideas[i] << std::endl;
	}
}
