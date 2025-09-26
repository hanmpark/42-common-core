/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:56:47 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 03:01:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::isDisplayable(char const &c) {
	return c >= 32 && c <= 126;
}

bool	ScalarConverter::isDigit(char const &c) {
	return c >= '0' && c <= '9';
}

long	ScalarConverter::stol(std::string const &str) {
	char	*endPtr;
	long	result = std::strtol(str.c_str(), &endPtr, 10);

	if (*endPtr != '\0')
		throw ConversionException();
	return result;
}

float	ScalarConverter::stof(std::string const &str) {
	char	*endPtr;
	float	result = std::strtof(str.c_str(), &endPtr);

	if (*endPtr != '\0' && *endPtr != 'f')
		throw ConversionException();
	return result;
}

double	ScalarConverter::stod(std::string const &str) {
	char	*endPtr;
	double	result = std::strtod(str.c_str(), &endPtr);

	if (*endPtr != '\0')
		throw ConversionException();
	return result;
}

char const	*ScalarConverter::ConversionException::what() const throw() { return "Bad conversion"; }
