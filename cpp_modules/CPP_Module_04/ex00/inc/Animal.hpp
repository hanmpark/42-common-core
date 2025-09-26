/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:23:06 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:44:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
protected:
	std::string _type;

public:
	Animal();
	Animal(Animal const &copy);
	virtual ~Animal();
	Animal	&operator=(Animal const &rhs);

	Animal(std::string type);

	std::string const	getType() const;
	virtual void		makeSound() const;
};

#endif