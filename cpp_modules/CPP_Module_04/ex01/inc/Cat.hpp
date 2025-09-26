/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:31:18 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:35:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *_brain;

public:
	Cat();
	Cat(Cat const &copy);
	virtual ~Cat();
	Cat	&operator=(Cat const &rhs);

	void	makeSound() const;
	void	telepathy(int nbr) const;
};

#endif