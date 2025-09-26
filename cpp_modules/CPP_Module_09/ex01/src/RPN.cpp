/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:04:55 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/30 12:52:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Canonical form

RPN::RPN() {}

RPN::RPN(RPN const &copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN	&RPN::operator=(RPN const &rhs) {
	if (this != &rhs)
		_stack = rhs._stack;

	return *this;
}

// private methods

int	RPN::add(int a, int b) {
	return a + b;
}

int	RPN::substract(int a, int b) {
	return a - b;
}

int	RPN::divide(int a, int b) {
	if (b == 0)
		throw DivisionByZeroException();
	return a / b;
}

int	RPN::multiply(int a, int b) {
	return a * b;
}

bool	RPN::isOperator(char const &c) const {
	return c == '+' || c == '-' || c == '/' || c == '*';
}

void	RPN::chooseOperation(char const &operand) {
	static t_op const	op[] = {
		{'+', &RPN::add},
		{'-', &RPN::substract},
		{'/', &RPN::divide},
		{'*', &RPN::multiply}
	};

	for (int i = 0; i < NB_OP; i++) {
		if (operand == op[i].c) {
			if (_stack.size() < 2) {
				throw NumberOperandsException();
			}
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			_stack.push((this->*op[i].ft)(a, b));
		}
	}
}

// Public method

void	RPN::calculate(string const &s) {
	bool	pushed = false;
	size_t	n = s.length();

	for (size_t i = 0; i < n; i++) {
		if (!pushed && isdigit(s.at(i))) {
			pushed = true;
			_stack.push(s.at(i) - '0');
		} else if (!pushed && isOperator(s.at(i))) {
			pushed = true;
			chooseOperation(s.at(i));
		} else if (!pushed || (pushed && s.at(i) != ' ') || (pushed && i + 1 == n)) {
			throw FormatException();
		} else {
			pushed = false;
		}
	}
	if (_stack.size() == 1 && n != 1) {
		cout << _stack.top() << endl;
	} else {
		throw FormatException();
	}
}

// Exceptions

char const	*RPN::NumberOperandsException::what() const throw() {
	return "wrong number of operands.";
}

char const	*RPN::FormatException::what() const throw() {
	return "format error.";
}

char const	*RPN::DivisionByZeroException::what() const throw() {
	return "Division by zero is impossible.";
}
