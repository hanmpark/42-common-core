/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:19:20 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:45:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}

	virtual void		learnMateria(AMateria *) = 0;
	virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif