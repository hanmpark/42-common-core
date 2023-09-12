/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:15:39 by hanmpark          #+#    #+#             */
/*   Updated: 2023/09/12 11:40:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*horde = new Zombie [N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
