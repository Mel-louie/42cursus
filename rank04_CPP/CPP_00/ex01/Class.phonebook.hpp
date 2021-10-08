/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:23:40 by louie             #+#    #+#             */
/*   Updated: 2021/10/08 13:05:32 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define MAX_CONTACT 8
# define MAX_WIDTH 10

using namespace std;

class Phonebook
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

void    search(Phonebook phonebook[], int index);
void	table_of_contents(void);
Phonebook	add();

#endif