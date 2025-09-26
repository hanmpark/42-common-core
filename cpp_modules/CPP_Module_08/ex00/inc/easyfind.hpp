/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:42:39 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/22 08:56:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <algorithm>

# define PURPLE	"\033[38;5;99m"
# define GREEN	"\033[38;5;115m"
# define RED	"\033[38;5;196m"
# define BOLD	"\033[1m"
# define DEF	"\033[0m"

template<typename T>
void	easyfind(T const &container, int integer) {
	if (std::find(container.begin(), container.end(), integer) != container.end())
		std::cout << "Found occurence" << std::endl;
	else
		throw std::exception();
}

#endif
