/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:16:54 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/17 12:37:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <ctime>

// randomly instanciates A, B or C and returns the instance as a Base pointer.
Base	*generate(void) {
	Base	*classes[3] = {
		new A,
		new B,
		new C
	};
	std::srand(std::time(NULL));
	int		randomNum = std::rand() % 3;

	// std::cout << "randomNum is " << randomNum << std::endl;
	return classes[randomNum];
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base *p) {
	std::cout << "Finding the type via its pointer" << std::endl;
	A	*isA = dynamic_cast<A *>(p);
	if (isA != NULL) {
		std::cout << "A" << std::endl;
		return ;
	}
	B	*isB = dynamic_cast<B *>(p);
	if (isB != NULL) {
		std::cout << "B" << std::endl;
		return ;
	}
	C	*isC = dynamic_cast<C *>(p);
	if (isC != NULL) {
		std::cout << "C" << std::endl;
		return ;
	}
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden.
void	identify(Base &p) {
	std::cout << "Finding the type via its reference" << std::endl;
	try {
		A	&isA = dynamic_cast<A &>(p);
		(void)isA;
		std::cout << "A" << std::endl;
		return ;
	} catch (std::bad_cast &bc) {}
	try {
		B	&isB = dynamic_cast<B &>(p);
		(void)isB;
		std::cout << "B" << std::endl;
		return ;
	} catch (std::bad_cast &bc) {}
	try {
		C	&isC = dynamic_cast<C &>(p);
		(void)isC;
		std::cout << "C" << std::endl;
		return ;
	} catch (std::bad_cast &bc) {}
}

int	main() {
	Base	*test = generate();

	identify(test);
	identify(*test);
	return 0;
}
