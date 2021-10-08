/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.contact.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:23:40 by louie             #+#    #+#             */
/*   Updated: 2021/10/08 13:56:07 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

using namespace std;

class Contact
{
public:
	void	set_fst_name(string);
	void	set_lst_name(string);
	void	set_nck_name(string);
	void	set_phone_num(string);
	void	set_darkest_scrt(string);
	
	string	get_fst_name(void);
	string	get_lst_name(void);
	string	get_nck_name(void);
	string	get_phone_num(void);
	string	get_darkest_scrt(void);
	
private:
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	darkest_secret;
};

//	FUNCTIONS

void	table_of_contents(void);


#endif
