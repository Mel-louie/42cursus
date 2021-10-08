/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:05:08 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 14:28:10 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.contact.hpp"
#include "Class.phonebook.hpp"

//Constructor

Phonebook::Phonebook(void)
{
	std::cout << "PhoneBook Creator Called" << std::endl;
	this->nb_contact = 0;
}

//Destructor

Phonebook::~Phonebook(void)
{
	std::cout << "PhoneBook Destructor Called" << std::endl;
}

void	Phonebook::table_of_contents(void)
{		
        string	choice;

		while (1)
        {
			if (!std::cin.eof())
	        {
				cout << "What do you want to do:" << endl;
				cout << "\tTo add a new contact, type ADD and press ENTER" << endl;
				cout << "\tTo search a contact, type SEARCH and press ENTER" << endl;
				cout << "\tTo exit, type EXIT and press ENTER" << endl;
			}
			getline(cin, choice);
			if (std::cin.eof()) {
				std::cout << std::endl;
				exit(0);
			}
			else if (choice == "EXIT")
				exit(0);
			else if (choice == "ADD")
				this->_addContact();
			else if (choice == "SEARCH")
				this->_searchContact();
		}
}

