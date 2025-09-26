/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:49:39 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/22 08:52:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

# define PURPLE	"\033[38;5;99m"
# define GREEN	"\033[38;5;115m"
# define BOLD	"\033[1m"
# define DEF	"\033[0m"

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack<T>() : std::stack<T>() {}
	MutantStack<T>(MutantStack<T> const &copy) : std::stack<T>(copy) {}
	virtual ~MutantStack<T>() {}
	MutantStack<T>	&operator=(MutantStack<T> const &rhs) {
		return std::stack<T>::operator=(rhs);
	}
	typedef typename std::deque<T>::iterator 		iterator;
	typedef typename std::deque<T>::const_iterator	const_iterator;
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
	const_iterator begin() const {
		return this->c.begin();
	}
	const_iterator end() const {
		return this->c.end();
	}
};

#endif
