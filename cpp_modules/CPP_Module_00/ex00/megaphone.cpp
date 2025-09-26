/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:18:54 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 21:37:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	make_loud_noise(std::string simple_noise) {
	for (size_t i = 0; i < simple_noise.size(); i++) {
		simple_noise.at(i) = std::toupper(simple_noise.at(i));
	}

	return simple_noise;
}

int	main(int argc, char **argv) {
	std::string	noise;

	if (argc < 2) {
		noise = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++) {
			std::string	argument = argv[i];
			noise += make_loud_noise(argument);
		}
	}

	std::cout << noise << std::endl;

	return 0;
}
