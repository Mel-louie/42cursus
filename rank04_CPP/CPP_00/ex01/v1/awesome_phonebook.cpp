/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/08 14:35:24 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.contact.hpp"

using namespace std;

void	table_of_contents(void)
{
	cout << "What do you want to do:" << endl;
	cout << "\tTo add a new contact, type ADD and press ENTER" << endl;
	cout << "\tTo search a contact, type SEARCH and press ENTER" << endl;
	cout << "\tTo exit, type EXIT and press ENTER" << endl;
}

int	main(void)
{
	Contact	phonebook[MAX_CONTACT];
	string	choice;
	int	contact_index;

	contact_index = 0;
	cout << "\n== Hello and wellcome to my Awesome PhoneBook! ==\n" << endl;
	table_of_contents();

	while (1)
	{
		getline(cin, choice);
		if (choice == "ADD")
		{
			if (contact_index < MAX_CONTACT)
				phonebook[contact_index++] = add();
			else
			{
				cout << "PhoneBook is full :(" << endl;
				table_of_contents();
			}
		}
		else if (choice == "SEARCH")
		{
			if (contact_index > 0)
				search(phonebook, contact_index);
			else
			{
				cout << "There is no contact for now!" << endl;
				table_of_contents();
			}
		}
		else if (choice == "EXIT")
			exit(0);
		else
			table_of_contents();		
		}
	return (0);
}
