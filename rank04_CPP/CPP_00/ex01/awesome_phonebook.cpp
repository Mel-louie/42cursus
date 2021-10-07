/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/09/10 12:09:06 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

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
			cout << "search\n";
			break ;
		}
		else if (!strcmp(choice, "EXIT"))
		{
			cout << "exit\n";
			//break ;
			exit(1);
		}
		else
		{
			cout << "Wrong option\n";
			table_of_contents();
			cin >> choice;
		}
	}
	return (0);
}
