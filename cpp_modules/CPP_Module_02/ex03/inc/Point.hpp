/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:02 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:29:59 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &copy);
	Point	&operator=(Point const &rhs);
	~Point(void);

	Fixed const	getX(void) const;
	Fixed const	getY(void) const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif