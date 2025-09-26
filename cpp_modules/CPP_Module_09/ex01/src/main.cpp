/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:45:42 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/30 10:37:45 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Error: wrong number of arguments." << endl;
		return 1;
	}

	RPN	rpn;

	try {
		rpn.calculate(static_cast<string>(argv[1]));
	} catch (std::exception &e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}
