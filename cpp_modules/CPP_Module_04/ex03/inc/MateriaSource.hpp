/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:05:53 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:45:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *_materias[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	virtual ~MateriaSource();
	MateriaSource	&operator=(MateriaSource const &rhs);

	AMateria	*getMateria(std::string const &type);
	AMateria	*createMateria(std::string const &type);
	void		learnMateria(AMateria *);
};

#endif