/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:09:26 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/15 16:48:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhonebook.hpp"

Phonebook::Phonebook()
{
	this->nb_of_contacts = 0;
	this->oldest = 0;
}

Phonebook::~Phonebook() {}

void	Phonebook::table_of_contents(void) const
{
	std::cout << "\n== Hello and welcome to my Awesome PhoneBook! ==\n" << std::endl;
	std::cout << "What do you want to do:" << std::endl;
	std::cout << "\tTo add a new contact, type ADD and press ENTER" << std::endl;
	std::cout << "\tTo search a contact, type SEARCH and press ENTER" << std::endl;
	std::cout << "\tTo exit, type EXIT and press ENTER" << std::endl;
}

void	Phonebook::replace_contact(void)
{
	std::cout << "The PhoneBook is full!" << std::endl
	<< "The oldest contact will be replace by the new one." << std::endl;
	if (this->oldest == 0)
	{
		this->contacts[0].set_informations(1);
		this->oldest += 1;
	}
	else
	{
		this->contacts[this->oldest].set_informations(this->oldest + 1);
		this->oldest += 1;
	}
	if (this->oldest == 8)
		this->oldest = 0;
}

void	Phonebook::add_contact(void)
{
	if (this->nb_of_contacts == 8)
		Phonebook::replace_contact();
	else
	{
		this->contacts[this->nb_of_contacts].set_informations(this->nb_of_contacts + 1);
		this->nb_of_contacts++;
	}
}

void	Phonebook::show_search_header(void)
{
	std::cout << std::endl; 
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->nb_of_contacts; i++)
		this->contacts[i].display_header();
}

void	Phonebook::search_contact(void)
{
	int	index;

	if (this->nb_of_contacts == 0)
		std::cout << "There is not contact :( Please add one." << std::endl;
	else
	{
		this->show_search_header();
		std::cout << std::endl << "Enter Index to display contact's informations, or 0 to exit SEARCH\n> ";
		if (!(std::cin >> index) || (index < 0 || index > this->nb_of_contacts))
		{
			std::cin.clear();
			std::cout << "/!\\ invalid index" << std::endl;
			return ;
		}
		if (index > 0 && index < 9)
			this->contacts[index - 1].display();
	}
}
