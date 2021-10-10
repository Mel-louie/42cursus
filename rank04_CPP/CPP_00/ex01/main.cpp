/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louie <louie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:00:09 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/10 15:43:13 by louie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook phonebook;
	bool run;
	std::string choice;

	phonebook.table_of_contents();
	run = true;
	while (run)
	{
		std::cout << std::endl << "> ";
		std::getline(std::cin, choice);
		if (choice == "ADD")
			phonebook.add_contact();
		else if (choice == "SEARCH")
			phonebook.search_contact();
		else if (choice == "EXIT")
		{
			std::cout << std::endl << "== Have a nice day! ==" << std::endl;
			run = false;
		}
	}
	std::cout << std::endl;
	return (0);
}
