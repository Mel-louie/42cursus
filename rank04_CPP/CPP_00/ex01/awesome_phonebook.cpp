/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/08 11:15:07 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.phonebook.hpp"

using namespace std;

void	table_of_contents(void)
{
	cout << "What do you want to do:" << endl;
	cout << "\tTo add a new contact, enter ADD" << endl;
	cout << "\tTo set, enter SEARCH" << endl;
	cout << "\tTo exit, enter EXIT" << endl;
}

int	main(void)
{
	char	choice[255];
	int	contact_index;

	contact_index = 0;
	cout << "\n== Hello and wellcome on my Awesome PhoneBook! ==\n" << endl;
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
