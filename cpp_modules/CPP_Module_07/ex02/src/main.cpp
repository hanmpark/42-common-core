/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:15:55 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/19 17:58:58 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main() {
	try {
		Array<int>			a1;
		Array<std::string>	a2(2);
		Array<int>			a3(1);

		// Checking basic stuff
		std::cout << BOLD PURPLE "Checking initialization" DEF << std::endl;
		std::cout << "Empty Array<int> a1:" << std::endl;
		std::cout << a1 << std::endl << std::endl;
		a2[0] = "hello";
		std::cout << "Array<std::string> a2:" << std::endl;
		std::cout << a2 << std::endl << std::endl;

		// Checking copy
		std::cout << BOLD PURPLE "Checking copy" DEF << std::endl;
		std::cout << GREEN "Copied Array<std::string> a2 to testCopy" DEF << std::endl;
		Array<std::string>	testCopy = a2;
		std::cout << "testCopy:" << std::endl;
		std::cout << testCopy << std::endl << std::endl;
		testCopy[0] = "wtf";
		std::cout << GREEN "Modified testCopy[0] = wtf" DEF << std::endl;
		std::cout << "testCopy:" << std::endl;
		std::cout << testCopy << std::endl;
		std::cout << "a2:" << std::endl;
		std::cout << a2 << std::endl << std::endl;

		// Checking [] operator
		std::cout << BOLD PURPLE "Checking [] operator" DEF << std::endl;
		std::cout << "Should work because array length == 1" << std::endl;
		std::cout << a3[0] << std::endl;
		std::cout << "Shouldn't work" << std::endl;
		std::cout << a3[1] << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
