/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:07:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:43:37 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
private:
	AMateria	*_inventory[4];
	AMateria	**_ground;
	std::string	_name;

	void	updateGround(AMateria *);
	int		countGroundItem() const;
	void	reorderItems();

public:
	Character();
	Character(Character const &copy);
	virtual ~Character();
	Character	&operator=(Character const &rhs);

	Character(std::string const &name);

	std::string const	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
	void				checkground() const;
};

#endif