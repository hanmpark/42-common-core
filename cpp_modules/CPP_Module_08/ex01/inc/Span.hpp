/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:45:05 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/22 08:49:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <ctime>
# include <cstdlib>

# define PURPLE	"\033[38;5;99m"
# define GREEN	"\033[38;5;115m"
# define RED	"\033[38;5;196m"
# define BOLD	"\033[1m"
# define DEF	"\033[0m"

class Span {
private:
	size_t				_N;
	std::vector<int>	_vec;
	Span();

public:
	Span(size_t N);
	Span(Span const &copy);
	~Span();
	Span	&operator=(Span const &rhs);

	// Getter
	std::vector<int> const	&getVec() const;

	// Method
	void			addNumber(unsigned int number);
	void			addNumber(std::vector<int>::const_iterator it, std::vector<int>::const_iterator it2);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	// Exceptions
	class OutOfBoundsException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class NoSpanException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Span &sp);

#endif
