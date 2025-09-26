/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:54:27 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:35:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *_brain;

public:
	Dog();
	Dog(Dog const &copy);
	virtual ~Dog();
	Dog	&operator=(Dog const &rhs);

	void	makeSound() const;
	void	telepathy(int nbr) const;
};

#endif