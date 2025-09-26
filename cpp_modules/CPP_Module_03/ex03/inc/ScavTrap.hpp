/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:41:57 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:27:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define PURPLE "\033[38;5;134m"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string const &Name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap	&operator=(ScavTrap const &rhs);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate();

protected:
	unsigned int	_ScavEnergyPoints;
};

#endif