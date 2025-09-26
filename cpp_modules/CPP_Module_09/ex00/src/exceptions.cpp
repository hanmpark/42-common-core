/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:50:22 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/30 12:35:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Exceptions

char const	*BitcoinExchange::OpenFileException::what() const throw() {
	return "could not open file.";
}

char const	*BitcoinExchange::FormatException::what() const throw() {
	return "wrong format.";
}

char const	*BitcoinExchange::NotPositiveNumberException::what() const throw() {
	return "not a positive number.";
}

char const	*BitcoinExchange::BadInputException::what() const throw() {
	return "bad input => ";
}

char const	*BitcoinExchange::TooLargeNumberException::what() const throw() {
	return "too large a number.";
}

char const	*BitcoinExchange::TooSmallNumberException::what() const throw() {
	return "too small a number.";
}

char const	*BitcoinExchange::NonDigitException::what() const throw() {
	return "non digit character found.";
}

char const	*BitcoinExchange::NoPreviousDateException::what() const throw() {
	return "no previous date in the .csv found.";
}
