/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:18 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/15 19:29:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

typedef bool	(*t_ftIs)(std::string const &literal);

typedef void	(*t_ftPrint)(std::string const &literal);

typedef struct s_dispatch {
	t_ftIs		ftIs;
	t_ftPrint	ftPrint;
}	t_dispatch;

class ScalarConverter {
private:
	// Utils
	static bool		isDisplayable(char const &c);
	static bool		isDigit(char const &c);
	static long		stol(std::string const &str);
	static float 	stof(std::string const &str);
	static double	stod(std::string const &str);

	// Checkers
	static bool	isChar(std::string const &literal);
	static bool	isInt(std::string const &literal);
	static bool	isFloat(std::string const &literal);
	static bool	isDouble(std::string const &literal);
	static bool	isPseudoLiteral(std::string const &literal);

	// Printers
	static void	charPrint(std::string const &literal);
	static void	intPrint(std::string const &literal);
	static void	floatPrint(std::string const &literal);
	static void	doublePrint(std::string const &literal);
	static void	displayPrint(char const &c, long const &i, float const &f, double const &d);

	ScalarConverter();

public:
	static void	convert(std::string const &literal);

	class ConversionException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class NotFoundTypeException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

#endif
