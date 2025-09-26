/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterPrint.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:18:14 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/15 19:28:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::displayPrint(char const &c, long const &i, float const &f, double const &d) {
	std::cout << "char: ";
	if (isDisplayable(c) == true)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non Displayable" << std::endl;

	std::cout << "int: ";
	if (i >= INT_MIN && i <= INT_MAX)
		std::cout << i << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "float: ";
	if (f > -FLT_MAX && f < FLT_MAX)
		std::cout << f << (f == i ? ".0f" : "f") << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "double: ";
	if (d > -DBL_MAX && d < DBL_MAX)
		std::cout << d << (d == i ? ".0" : "") << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

void	ScalarConverter::charPrint(std::string const &literal) {
	// std::cout << "printing char" << std::endl;
	char const		c = literal.at(0);
	long const		i = static_cast<long>(c);
	float const		f = static_cast<float>(c);
	double const	d = static_cast<double>(c);

	displayPrint(c, i, f, d);
}

void	ScalarConverter::intPrint(std::string const &literal) {
	// std::cout << "printing int" << std::endl;
	long const		i = stol(literal);
	char const		c = static_cast<char>(i);
	float const		f = static_cast<float>(i);
	double const	d = static_cast<double>(i);

	displayPrint(c, i, f, d);
}

void	ScalarConverter::floatPrint(std::string const &literal) {
	// std::cout << "printing float" << std::endl;
	float const		f = stof(literal);
	char const		c = static_cast<char>(f);
	long const		i = static_cast<long>(f);
	double const	d = static_cast<double>(f);

	displayPrint(c, i, f, d);
}

void	ScalarConverter::doublePrint(std::string const &literal) {
	// std::cout << "printing double" << std::endl;
	double const	d = stod(literal);
	char const		c = static_cast<char>(d);
	long const		i = static_cast<long>(d);
	float const		f = static_cast<float>(d);

	displayPrint(c, i, f, d);
}
