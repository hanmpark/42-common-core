/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:34:55 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 03:00:36 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy.getName()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	(void)rhs;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :	AForm(target, 145, 137), _target(target) {}

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const {
	if (this->getSigned() == false)
		throw AForm::FormUnsignedException();
	else if (this->getGradeToExecute() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	file((this->getName() + "_shrubbery").c_str());
	if (file.is_open() == false)
		throw CreateFileException();
	file << "                                   .         ;     " << std::endl;
	file << "      .              .              ;%     ;;      " << std::endl;
	file << "        ,           ,                :;%  %;       " << std::endl;
	file << "         :         ;                   :;%;'     .," << std::endl;
	file << ",.        %;     %;            ;        %;'    ,;  " << std::endl;
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << std::endl;
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    " << std::endl;
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'      " << std::endl;
	file << "     `%;.     ;%;     %;'         `;%%;.%;'        " << std::endl;
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'           " << std::endl;
	file << "         `:%;.  :;bd%;          %;@%;'             " << std::endl;
	file << "           `@%:.  :;%.         ;@@%;'              " << std::endl;
	file << "             `@%.  `;@%.      ;@@%;                " << std::endl;
	file << "               `@%%. `@%%    ;@@%;                 " << std::endl;
	file << "                 ;@%. :@%%  %@@%;                  " << std::endl;
	file << "                   %@bd%%%bd%%:;                   " << std::endl;
	file << "                     #@%%%%%:;;                    " << std::endl;
	file << "                     %@@%%%::;                     " << std::endl;
	file << "                     %@@@%(o);  . '                " << std::endl;
	file << "                     %@@@o%;:(.,'                  " << std::endl;
	file << "                 `.. %@@@o%::;                     " << std::endl;
	file << "                    `)@@@o%::;                     " << std::endl;
	file << "                     %@@(o)::;                     " << std::endl;
	file << "                    .%@@@@%::;                     " << std::endl;
	file << "                    ;%@@@@%::;.                    " << std::endl;
	file << "                   ;%@@@@%%:;;;.                   " << std::endl;
	file << "               ...;%@@@@@%%:;;;;,..                " << std::endl;
	file.close();
}

char const	*ShrubberyCreationForm::CreateFileException::what() const throw() { return "Could not create the file"; }
