/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:11:33 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/18 19:41:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main() {
	int			num[] = {3, 2, 1, -1, 42};
	float		numf[] = {3.2f, 2.1f, 1.0f, -1.123f, 42.042f};
	char		str1[] = "Caca houete";
	std::string	str2[] = {
		"Hello",
		"World",
		"My",
		"Name",
		"Is",
		"Hanmin"
	};

	std::cout << "Printing integers" << std::endl;
	iter(num, 5, &print_index);
	std::cout << "Printing floats" << std::endl;
	iter(numf, 5, &print_index);
	std::cout << "Printing strings" << std::endl;
	iter(str1, 11, &print_index);
	std::cout << "Printing chars" << std::endl;
	iter(str2, 6, &print_index);
	return 0;
}
