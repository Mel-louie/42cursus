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

int	main(void)
{
	char	choice[255];

	cout << "\n== Hello and wellcome on my Awesome PhoneBook! ==\n\n";
	cout << "What do you want to do:\n";
	cout << "\tTo add a new contact, enter ADD\n";
	cout << "\tTo set, enter SEARCH\n";
	cout << "\tTo exit, enter EXIT\n";
	cin >> choice;

	if (!strcmp(choice, "ADD"))
		cout << "add\n";
	else if (!strcmp(choice, "SEARCH"))
		cout << "search\n";
	else if (!strcmp(choice, "EXIT"))
		cout << "exit\n";
	else
		cout << "nothing\n";
	return (0);
}