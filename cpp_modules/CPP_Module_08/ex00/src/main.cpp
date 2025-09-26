/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:42:19 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/22 08:51:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

static void	print_index(int const &i) {
	std::cout << i << std::endl;
}

int	main() {
	try {
		std::list<int>	listInt;
		int				find = 42;
		int				noExist = -1321;

		listInt.push_back(1);
		listInt.push_back(2);
		listInt.push_back(find);
		listInt.push_back(-42);

		std::cout << "---------------------------------------" << std::endl;
		std::cout << BOLD PURPLE "Elements in the list: " DEF << std::endl;
		std::for_each(listInt.begin(), listInt.end(), print_index);
		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << GREEN "Trying to find '" << find << "' in the list:" DEF << std::endl;
		easyfind(listInt, find);
		std::cout << GREEN "Trying to find '" << noExist << "' in the list:" DEF << std::endl;
		easyfind(listInt, noExist);
	} catch (std::exception &e) {
		std::cerr << BOLD RED "Error: Couldn't find any occurence." DEF << std::endl;
	}
	return 0;
}
