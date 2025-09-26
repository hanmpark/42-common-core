/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:03:57 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 03:04:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cctype>

# define NB_OP 4

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stack;

class RPN {
private:
	stack<int>	_stack;

	// Private methods

	bool	isOperator(char const &c) const;
	void	chooseOperation(char const &operand);
	int		add(int a, int b);
	int		substract(int a, int b);
	int		divide(int a, int b);
	int		multiply(int a, int b);

	typedef int	(RPN::*t_ft)(int a, int b);
	typedef struct s_op {
		char	c;
		t_ft	ft;
	}	t_op;

public:
	RPN();
	RPN(RPN const &copy);
	~RPN();
	RPN	&operator=(RPN const &rhs);

	// Public method

	void	calculate(string const &s);

	// Exceptions

	class NumberOperandsException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class FormatException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class DivisionByZeroException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

#endif
