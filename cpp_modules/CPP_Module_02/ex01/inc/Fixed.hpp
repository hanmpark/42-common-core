/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:53:50 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:24:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(Fixed const &copy);
	Fixed	&operator=(Fixed const &rhs);
	~Fixed();

	Fixed(int const d);
	Fixed(float const f);

	int		getRawBits() const;
	void 	getRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

private:
	int					_fixedPointValue;
	static int const	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fp);

#endif