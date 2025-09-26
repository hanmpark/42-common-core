/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:32:42 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/22 08:50:22 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	generateRand() {
	return std::rand();
}

int	main() {
	{
		std::cout << BOLD PURPLE "Subject main:" DEF << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	try {
		std::vector<int>	vec(10000);
	
		std::srand(time(NULL));
		std::generate(vec.begin(), vec.end(), std::rand);
	
		Span	sp1 = Span(vec.size());
		sp1.addNumber(vec.begin(), vec.end());

		std::cout << BOLD PURPLE "Test for multiple add:" DEF << std::endl;
		std::cout << sp1 << std::endl << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED BOLD "Error: " << e.what() << DEF << std::endl;
	}
	try {
		std::cout << BOLD PURPLE "Test for OutOfBounds exception:" DEF << std::endl;
		Span	sp2(0);
		std::cout << GREEN "Trying to add an element..." DEF << std::endl;
		sp2.addNumber(1);
	} catch (std::exception &e) {
		std::cerr << RED BOLD "Error: " << e.what() << DEF << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << BOLD PURPLE "Test for exceptions:" DEF << std::endl;
		Span	sp2(0);
		std::cout << GREEN "Trying to find the longest span in an empty Span..." DEF<< std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED BOLD "Error: " << e.what() << DEF << std::endl;
	}
	return 0;
}
