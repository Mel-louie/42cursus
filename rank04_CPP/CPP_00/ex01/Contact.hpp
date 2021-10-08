/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louie <louie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:04:23 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 18:15:03 by louie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	int					index;
	static std::string	fields_name[5];
	std::string			informations[5];

	enum Field {
		FirstName = 0,
		LastName,
		Nickname,
		PhoneNumber,
		Secret
	};
public:
	Contact();
	virtual ~Contact();

	bool	set_informations(int index);
	void	display_header(void);
	void	display(void);
};

#endif