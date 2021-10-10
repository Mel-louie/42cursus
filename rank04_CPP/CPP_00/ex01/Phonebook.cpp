/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louie <louie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:09:26 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/10 15:37:18 by louie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->nb_of_contacts = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::table_of_contents(void)
{
	std::cout << "\n== Hello and welcome to my Awesome PhoneBook! ==\n" << std::endl;
	std::cout << "What do you want to do:" << std::endl;
	std::cout << "\tTo add a new contact, type ADD and press ENTER" << std::endl;
	std::cout << "\tTo search a contact, type SEARCH and press ENTER" << std::endl;
	std::cout << "\tTo exit, type EXIT and press ENTER" << std::endl;
}

void Phonebook::add_contact(void)
{
	if (this->nb_of_contacts == 8)
		std::cout << "The PhoneBook is full!" << std::endl;
	else
	{
		this->contacts[this->nb_of_contacts].set_informations(this->nb_of_contacts + 1);
		this->nb_of_contacts++;
	}
}

void Phonebook::show_search_header(void)
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < this->nb_of_contacts; i++)
		this->contacts[i].display_header();
}

void Phonebook::search_contact(void)
{
	int	index;

	if (this->nb_of_contacts == 0)
		std::cout << "There is not contact :( Please add one." << std::endl;
	else
	{
		this->show_search_header();
		std::cout << "Enter Index to display contact's informations\n> ";
		while (!(std::cin >> index) || (index < 0 || index > this->nb_of_contacts))
		{
			std::cin.clear();
			std::cout << "invalid index\n~";
		}
		if (index > 0)
			this->contacts[index - 1].display();
	}
}
