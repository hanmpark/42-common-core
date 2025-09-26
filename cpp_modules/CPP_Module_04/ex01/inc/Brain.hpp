/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:31:51 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:34:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
private:
	std::string _ideas[100];

public:
	Brain()
	Brain(Brain const &copy)
	virtual ~Brain()
	Brain	&operator=(Brain const &rhs)

	Brain(std::string const &animalType);

	void	sayIdeas(int nbr) const;
};

#endif