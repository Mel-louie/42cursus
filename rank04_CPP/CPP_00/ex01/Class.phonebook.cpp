/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:05:08 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 14:30:03 by mdesfont         ###   ########.fr       */
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
				this->add();
			else if (choice == "SEARCH")
				this->search();
		}
}

void	Phonebook::search(void) {
	if (!this->_nbContact) {
		std::cout << "No contacts in phoneBook" << std::endl;
		return ;	
	}
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	for (int i = 0 ; i < _nbContact ; i++) {
		std::cout << "|" << std::right << std::setw(10) << i;
		this->_contacts[i].printContact();
	}
	int	index;
	std::cout << "Type in contact index: ";
	std::cin >> index;
	if (std::cin.fail() || index >= this->_nbContact || index < 0) {
		std::cout << "Please type in an integer between 0 and " << this->_nbContact - 1 << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	else {
		this->_contacts[index].printFullContact();
		std::cin.ignore(INT_MAX, '\n');
	}
	return ;
}
