/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louie <louie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/07 16:59:00 by louie            ###   ########.fr       */
/*https://github.com/jraleman/42_Piscine-CPP/blob/master/day00/ex01/main.cpp                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "awesome_phonebook.hpp"

using namespace std;

void	table_of_contents(void)
{
	cout << "What do you want to do:\n";
	cout << "\tTo add a new contact, enter ADD\n";
	cout << "\tTo set, enter SEARCH\n";
	cout << "\tTo exit, enter EXIT\n";
}

int	main(void)
{
	char	choice[255];
	int	contact_index;

	contact_index = 0;
	cout << "\n== Hello and wellcome on my Awesome PhoneBook! ==\n\n";
	table_of_contents();
	cin >> choice;

	while (1)
	{
		if (!strcmp(choice, "ADD"))
		{
			cout << "add\n";
			break ;
		}
		else if (!strcmp(choice, "SEARCH"))
		{
			if (contact_index > 0)
				cout << "lol" << endl;
			else
			{
				cout << "There is no contact for now!" << endl;
				table_of_contents();
				cin >> choice;
			}
		}
		else if (!strcmp(choice, "EXIT"))
		{
			cout << "exit\n";
			//break ;
			exit(1);
		}
		else
		{
			table_of_contents();
			cin >> choice;
		}
	}
	return (0);
}
