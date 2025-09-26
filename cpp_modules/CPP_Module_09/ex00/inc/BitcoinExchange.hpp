/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:00:43 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 03:03:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <fstream>
# include <sstream>
# include <cctype>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;

typedef enum e_type {
	CSV,
	TXT
}	t_type;

class BitcoinExchange {
private:
	map<string, double>	_map;
	string				_rawInput;
	int					_year, _month, _day;

	// Private methods

	void	checkExtension(string const &filename, string const &extension) const;
	void	readFile(string const &filename);
	void	readDataBase(string const &name, char const &limiter);
	double	findExchangeRate();

	string	getDate(string const &date);
	double	getValue(string const &value, t_type type);
	bool	checkLeapYear(int const &year);
	bool	isPreviousDate(int const &year, int const &month, int const &day);

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange();
	BitcoinExchange	&operator=(BitcoinExchange const &rhs);

	// Public methods

	void	readInput(string const &filename);
	void	printResult();

	// Exceptions

	class OpenFileException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class FormatException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class NotPositiveNumberException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class BadInputException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class TooLargeNumberException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class TooSmallNumberException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class NonDigitException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class NoPreviousDateException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

#endif
