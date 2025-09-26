/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:33:38 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:45:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const &copy);
	virtual ~Ice();
	Ice	&operator=(Ice const &rhs);

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif