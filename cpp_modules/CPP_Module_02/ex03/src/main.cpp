/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:54:17 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:20:25 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main() {
	Point const	a(2.5f, 5.f);
	Point const	b(4.25f, 3.67f);
	Point const	c(1.06f, 4.765f);
	Point const	d(3.4f, 4.2f);

	if (bsp(a, b, c, d)) {
		std::cout << "Point is INSIDE the triangle" << std::endl;
	} else {
		std::cout << "Point is OUTSIDE the triangle" << std::endl;
	}
	return 0;
}
