/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:10:57 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/19 18:00:10 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T *array, size_t length, void (*f)(T &)) {
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template<typename T>
void	print_index(T &index) {
	std::cout << index << std::endl;
}

#endif
