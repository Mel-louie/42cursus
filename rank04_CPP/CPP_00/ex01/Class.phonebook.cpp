/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:23:40 by louie             #+#    #+#             */
/*   Updated: 2021/10/08 12:55:17 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.phonebook.hpp"


string	Phonebook::get_fst_name()
{
	return (first_name);
}

string	Phonebook::get_lst_name()
{
	return (last_name);
}

string	Phonebook::get_nck_name()
{
	return (nickname);
}

string	Phonebook::get_phone_num()
{
	return (phone_number);
}

string Phonebook::get_darkest_scrt()
{
	return (darkest_secret);
}

void	Phonebook::set_fst_name(string s)
{
	this->first_name = s;
	return ;
}

void	Phonebook::set_lst_name(string s)
{
	this->last_name = s;
	return ;
}

void	Phonebook::set_nck_name(string s)
{
	this->nickname = s;
	return ;
}

void	Phonebook::set_phone_num(string s)
{
	this->phone_number = s;
	return ;
}

void	Phonebook::set_darkest_scrt(string s)
{
	this->darkest_secret = s;
	return ;
}
