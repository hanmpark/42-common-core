/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:10:57 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 21:30:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# define RED	"\033[38;5;204m"
# define BLUE	"\033[38;5;32m"
# define GREEN	"\033[38;5;80m"
# define YELLOW	"\033[38;5;184m"
# define DEF	"\033[0m"

class Contact {
public:
	Contact(void);
	~Contact(void);

	void	setFirstName(std::string first_name);
	void	setLastName(std::string last_name);
	void	setNickName(std::string nickname);
	void	setPhoneNumber(std::string phone_number);
	void	setDarkestSecret(std::string darkest_secret);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;
};

#endif
