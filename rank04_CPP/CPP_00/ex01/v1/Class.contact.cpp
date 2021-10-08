/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:23:40 by louie             #+#    #+#             */
/*   Updated: 2021/10/08 14:40:45 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.contact.hpp"

//Constructor

Contact::Contact( void ) {}

//Destructor

Contact::~Contact( void ) {}


string	Contact::get_fst_name()
{
	return (first_name);
}

string	Contact::get_lst_name()
{
	return (last_name);
}

string	Contact::get_nck_name()
{
	return (nickname);
}

string	Contact::get_phone_num()
{
	return (phone_number);
}

string Contact::get_darkest_scrt()
{
	return (darkest_secret);
}

void	Contact::set_fst_name(string s)
{
	this->first_name = s;
	return ;
}

void	Contact::set_lst_name(string s)
{
	this->last_name = s;
	return ;
}

void	Contact::set_nck_name(string s)
{
	this->nickname = s;
	return ;
}

void	Contact::set_phone_num(string s)
{
	this->phone_number = s;
	return ;
}

void	Contact::set_darkest_scrt(string s)
{
	this->darkest_secret = s;
	return ;
}
