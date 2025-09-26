/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:57 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 21:38:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <cstdlib>

int	main() {
	PhoneBook	phonebook;

	while (1) {
		std::string command;
		std::cout << YELLOW "Enter a command (ADD, SEARCH, EXIT): " DEF;
		std::getline(std::cin, command);

		if (std::cin.eof()) {
			exit(1);
		} else if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.searchContact();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << RED "Command does not exist" DEF << std::endl;
		}
	}

	return 0;
}
