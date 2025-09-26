/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:57:50 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:14:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define RED		"\033[38;5;204m"
#define GREEN	"\033[38;5;80m"
#define DEF		"\033[0m"

static bool	getContent(std::string const fileName, std::string &content, std::string const occurrence, std::string const replace) {
	std::ifstream	ifs;

	ifs.open(fileName, std::ifstream::in);
	if (!ifs.is_open())
		return false;
	std::getline(ifs, content, '\0');
	ifs.close();

	size_t	pos;
	int		countOccurrence = 0;
	while ((pos = content.find(occurrence)) != std::string::npos) {
		content.erase(pos, occurrence.size());
		content.insert(pos, replace);
		countOccurrence++;
	}

	if (countOccurrence > 0) {
		std::cout << GREEN "Found " << countOccurrence << " occurrence(s) of \"" << occurrence << "\" in " << fileName << DEF << std::endl;
	} else {
		std::cout << GREEN << fileName << " contains no occurence of \"" << occurrence << "\"" << DEF << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << RED "Error: Wrong number of arguments" DEF << std::endl;
		return 1;
	}

	std::string const	occurrence = argv[2];
	std::string const	replace = argv[3];
	std::string			fileName = argv[1];
	std::string			content;

	if (!getContent(fileName, content, occurrence, replace)) {
		std::cerr << RED "Error: Something wrong occurred opening/reading the file" DEF << std::endl;
		return 1;
	}

	std::ofstream ofs;
	ofs.open(fileName.append(".replace"), std::ofstream::out);
	ofs << content;
	ofs.close();

	return 0;
}
