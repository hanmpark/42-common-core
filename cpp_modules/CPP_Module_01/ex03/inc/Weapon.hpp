/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:27:00 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:11:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
public:
	Weapon(std::string weapon);
	~Weapon();

	std::string const	&getType() const;
	void				setType(std::string newValue);

private:
	std::string _type;
};

#endif