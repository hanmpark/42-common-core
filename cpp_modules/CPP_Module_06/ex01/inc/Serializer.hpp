/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:37:02 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/16 14:38:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# include "Data.hpp"

struct Data;

class Serializer {
private:
	Serializer();

public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif
