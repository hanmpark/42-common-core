/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:57:23 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/18 08:48:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	Data		*data;
	uintptr_t	serializedData;
	Data		*checkData;

	data = new Data;
	std::cout << "data address             : " << data << std::endl;
	serializedData = Serializer::serialize(data);
	std::cout << "serializedData address   : " << serializedData << std::endl;
	checkData = Serializer::deserialize(serializedData);
	std::cout << "deserializedData address : " << checkData << std::endl;
	return 0;
}
