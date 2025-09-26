/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getData.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:51:30 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/30 12:36:24 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::checkLeapYear(int const &year) {
	return (!(year % 4) && year % 100) || !(year % 400);
}

string	BitcoinExchange::getDate(string const &date) {
	char				c;
	std::istringstream	ss(date);

	ss >> _year >> c >> _month >> c >> _day;
	if (date.find('-') == date.rfind('-') || ss.fail() || ss.get() != EOF || !(_year > 999 && _year < 10000))
		throw BadInputException();

	if (_month < 1 || _month > 12)
		throw BadInputException();

	int	daysMonth = 31;

	if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
		daysMonth = 30;
	} else if (_month == 2) {
		if (checkLeapYear(_year)) {
			daysMonth = 29;
		} else {
			daysMonth = 28;
		}
	}
	if (_day < 1 || _day > daysMonth) {
		throw BadInputException();
	}

	return date;
}

double	BitcoinExchange::getValue(string const &value, t_type type) {
	int	count = 0;

	for (size_t i = 0; i < value.length(); i++) {
		if (!i && value.at(i) == '-') {
			throw NotPositiveNumberException();
		} else if (std::isdigit(value.at(i)) == false && value.at(i) != '.') {
			throw NonDigitException();
		} else if (value.at(i) == '.') {
			count++;
		}
	}
	if (count > 1)
		throw FormatException();

	std::istringstream	sv(value);
	double				val;
	sv >> val;
	if (sv.fail()) {
		throw FormatException();
	} else if ((type == CSV && val < 0.0) || (type == TXT && val <= 0.0)) {
		throw TooSmallNumberException();
	} else if (type == TXT && val >= 1000.0) {
		throw TooLargeNumberException();
	}

	return val;
}
