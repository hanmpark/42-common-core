/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:14:07 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:43:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &copy);
	virtual ~WrongAnimal();
	WrongAnimal	&operator=(WrongAnimal const &rhs);

	WrongAnimal(std::string type);

	std::string const	getType() const;
	void				makeSound() const;
};

#endif