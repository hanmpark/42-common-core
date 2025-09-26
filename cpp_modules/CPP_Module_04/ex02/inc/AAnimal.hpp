/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:23:06 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:43:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(AAnimal const &copy);
	virtual ~AAnimal();
	AAnimal	&operator=(AAnimal const &rhs);

	AAnimal(std::string type);

	std::string const	getType() const;
	virtual void		makeSound() const = 0;
	virtual void		telepathy(int nbr) const = 0;
};

#endif