/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:54:11 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:22:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable ! I want to speak to the manager now."

# define RED "\033[38;5;204m"
# define GREEN "\033[38;5;80m"
# define BLUE "\033[38;5;32m"
# define DEF "\033[0m"

class Harl {
public:
	Harl();
	~Harl();

	void	complain(std::string level);

private:
	typedef void	(Harl::*harl_function_t)();

	struct Level {

		harl_function_t complainLevel;
		std::string level;
	};

	void	debug();
	void	info();
	void	warning();
	void	error();
};

#endif