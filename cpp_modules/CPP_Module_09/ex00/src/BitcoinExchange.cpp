/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:03:20 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/02 07:59:36 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _year(0), _month(0), _day(0) {
	readFile("data.csv");
	readDataBase("date,exchange_rate", ',');
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		_map = rhs._map;
		_rawInput = rhs._rawInput;
		_year = rhs._year;
		_month = rhs._month;
		_day = rhs._day;
	}

	return *this;
}

// Private methods

void	BitcoinExchange::checkExtension(string const &filename, string const &extension) const {
	if (filename.length() < extension.length() || filename.substr(filename.length() - extension.length()) != extension)
		throw FormatException();
}

void	BitcoinExchange::readFile(string const &filename) {
	std::ifstream	file(filename.c_str());

	if (file.is_open() == false)
		throw OpenFileException();
	std::getline(file, _rawInput, '\0');
	if (file.fail())
		throw FormatException();
	file.close();
}

void	BitcoinExchange::readDataBase(string const &name, char const &limiter) {
	std::stringstream	iss(_rawInput);
	string				line;

	std::getline(iss, line);
	if (line != name || iss.fail())
		throw FormatException();
	while (std::getline(iss, line)) {
		for (size_t i = 0; i < line.length(); i++) {
			if (line.at(i) == limiter) {
				if (i + 1 == line.length())
					throw FormatException();
				_map[getDate(line.substr(0, i))] = getValue(line.substr(i + 1), CSV);
			}
		}
	}
}

bool	BitcoinExchange::isPreviousDate(int const &year, int const &month, int const &day) {
	if (_year < year) {
		return true;
	} else if (_year == year && _month < month) {
		return true;
	} else if (_year == year && _month == month && _day <= day) {
		return true;
	}

	return false;
}

double	BitcoinExchange::findExchangeRate() {
	map<string, double>::const_iterator	it;
	double								exchangeRate = -1;
	int									year = _year, month = _month, day = _day;

	for (it = _map.begin(); it != _map.end(); it++) {
		getDate(it->first);
		if (isPreviousDate(year, month, day) == true) {
			exchangeRate = it->second;
		} else {
			break;
		}
	}

	return exchangeRate;
}

// Public methods

void	BitcoinExchange::readInput(string const &filename) {
	readFile(filename);

	std::istringstream	iss(_rawInput);
	string				line;

	std::getline(iss, line);
	if (line != "date | value" || iss.fail())
		throw FormatException();
	std::getline(iss, line);
	if (iss.fail())
		throw FormatException();
}

void	BitcoinExchange::printResult() {
	std::stringstream	iss(_rawInput);
	string				line;

	std::getline(iss, line);
	while (std::getline(iss, line)) {
		size_t	i;
		try {
			if ((i = line.find(" | ")) == string::npos)
				throw BadInputException();

			string	date = getDate(line.substr(0, i));
			double	value = getValue(line.substr(i + 3), TXT);
			double	exchangeRate;

			if ((exchangeRate = findExchangeRate()) == -1)
				throw NoPreviousDateException();
			cout << date << " => " << value << " = " << value * exchangeRate << endl;
		} catch (BadInputException &e) {
			cout << "Error: " << e.what() << line.substr(0, i) << endl;
		} catch (std::exception &e) {
			cout << "Error: " << e.what() << endl;
		}
	}
}
