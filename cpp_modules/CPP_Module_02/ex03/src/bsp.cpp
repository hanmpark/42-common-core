/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:13:16 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:18:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getArea(Point const a, Point const b, Point const c) {
	float const sumArea = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) \
		+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) \
		+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));

	std::cout << sumArea << std::endl;
	return sumArea;
}

/*
* Here I am not turning the values in their absolute value because when multiplying floats by -1
* we loose some precision and it could false the result
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float A_abc = getArea(a, b, c);
	float A_dbc = getArea(point, b, c);
	float A_dca = getArea(point, c, a);
	float A_dab = getArea(point, a, b);

	std::cout << "sum of the area is = " << A_dbc + A_dca + A_dab << std::endl;

	return A_abc == A_dbc + A_dca + A_dab && A_dbc < 0.0f && A_dca < 0.0f && A_dab < 0.0f;
}
