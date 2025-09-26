/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:09 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/19 18:01:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &a, T &b) {
	T	c = a;

	a = b;
	b = c;
}

template<typename T>
T const	&min(T const &a, T const &b) {
	if (a < b)
		return a;
	return b;
}

template<typename T>
T const	&max(T const &a, T const &b) {
	if (a > b)
		return a;
	return b;
}

#endif
