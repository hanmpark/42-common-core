/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:52:37 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:44:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const &copy);
	virtual ~Cure();
	Cure	&operator=(Cure const &rhs);

	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif