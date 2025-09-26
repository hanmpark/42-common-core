/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:53:50 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:23:20 by hanmpark         ###   ########.fr       */
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

	int		getRawBits() const;
	void	setRawBits(int const raw);

private:
	int					_fixedPointValue;
	static int const	_fractionalBits = 8;
};

#endif