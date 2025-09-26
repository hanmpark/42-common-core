/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:08:46 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/30 10:37:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Error: could not open file." << endl;
		return 1;
	}

	try {
		BitcoinExchange	btc;

		btc.readInput(static_cast<string>(argv[1]));
		btc.printResult();
	} catch (std::exception &e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}
