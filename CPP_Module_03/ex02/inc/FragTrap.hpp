/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:28:00 by hanmpark          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:18 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define ROSE "\033[38;5;218m"

class	FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string const &Name);
	FragTrap(FragTrap const &copy);
	FragTrap	&operator=(FragTrap const &rhs);
	~FragTrap();

	void	highFivesGuys();
};

#endif