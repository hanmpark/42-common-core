/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:08:12 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:27:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define YELLOW "\033[38;5;227m"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	DiamondTrap();
	DiamondTrap(std::string const &Name);
	DiamondTrap(DiamondTrap const &copy);
	DiamondTrap	&operator=(DiamondTrap const &rhs);
	~DiamondTrap();

	void	attack(const std::string &target);
	void	whoAmI();

private:
	std::string	_Name;
};

#endif