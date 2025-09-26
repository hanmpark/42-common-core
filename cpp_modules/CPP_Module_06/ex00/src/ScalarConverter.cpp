/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:43:22 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 03:01:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::isChar(std::string const &literal) {
	return literal.length() == 1 && isDisplayable(literal.at(0)) && isDigit(literal.at(0)) == false;
}

bool	ScalarConverter::isInt(std::string const &literal) {
	for (size_t i = literal.at(0) == '-' || literal.at(0) == '+'; i < literal.length(); i++) {
		if (isDigit(literal.at(i)) == false)
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloat(std::string const &literal) {
	size_t	countDot = 0;

	if (literal.at(literal.length() - 1) != 'f')
		return false;
	for (size_t i = literal.at(0) == '-' || literal.at(0) == '+'; i < literal.length(); i++) {
		if (isDigit(literal.at(i)) == false && (literal.at(i) == '.' || literal.at(i) == 'f'))
			countDot += literal.at(i) == '.';
		else if (isDigit(literal.at(i)) == false)
			return false;
	}
	return countDot == 1;
}

bool	ScalarConverter::isDouble(std::string const &literal) {
	size_t	countDot = 0;

	for (size_t i = literal.at(0) == '-' || literal.at(0) == '+'; i < literal.length(); i++) {
		if (isDigit(literal.at(i)) == false && literal.at(i) == '.')
			countDot++;
		else if (isDigit(literal.at(i)) == false)
			return false;
	}
	return countDot == 1;
}

bool	ScalarConverter::isPseudoLiteral(std::string const &literal) {
	static std::string const	pseudo[6] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};
	for (size_t i = 0; i < 6; i++) {
		if (literal == pseudo[i]) {
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: " << pseudo[(i < 3 ? i : i - 3)] << std::endl;
			std::cout << "double: " << pseudo[(i < 3 ? i + 3 : i)] << std::endl;
			return true;
		}
	}
	return false;
}

void	ScalarConverter::convert(std::string const &literal) {
	static t_dispatch const	dispatch[5] = {
		{&isPseudoLiteral, NULL},
		{&isChar, &charPrint},
		{&isInt, &intPrint},
		{&isFloat, &floatPrint},
		{&isDouble, &doublePrint}
	};
	for (size_t i = 0; i < 5; i++) {
		if (!i && dispatch[i].ftIs(literal)) {
			return ;
		} else if (dispatch[i].ftIs(literal)) {
			return (dispatch[i].ftPrint(literal));
		}
	}
	throw NotFoundTypeException();
}

char const	*ScalarConverter::NotFoundTypeException::what() const throw() { return "Incorrectly formatted number"; }
