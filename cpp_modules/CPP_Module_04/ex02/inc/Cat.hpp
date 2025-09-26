/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:31:18 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:38:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
private:
	Brain	*_brain;

public:
	Cat();
	Cat(Cat const &copy);
	virtual ~Cat();
	Cat	&operator=(Cat const &rhs);

	void	makeSound() const;
	void	telepathy(int nbr) const;
 };

#endif