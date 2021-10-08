/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_phonebook.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:16:28 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 13:24:57 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.phonebook.hpp"

string	trunc(string name)
{
	name = name.erase(MAX_WIDTH - 1, name.length() - (MAX_WIDTH - 1));
	name.append(".");
	return(name);
}

void	search(Phonebook phonebook[], int num_contact)
{
	string	fst_name;
	string	lst_name;
	string	nck_name;
	int	i = 0;
	int	index = 1;

	cout << "     index|first name| last name|  nickname" << endl;
	while (i < num_contact)
	{
		fst_name = phonebook[i].get_fst_name();
		lst_name = phonebook[i].get_lst_name();
		nck_name = phonebook[i].get_nck_name();

		if (fst_name.length() > MAX_WIDTH)
			fst_name = trunc(fst_name);
		if (lst_name.length() > MAX_WIDTH)
			lst_name = trunc(lst_name);
		if (nck_name.length() > MAX_WIDTH)
			nck_name = trunc(nck_name);
		
		cout << setw(10) << index << "|";
		cout << setw(10) << fst_name << "|";
		cout << setw(10) << lst_name <<"|";
		cout << setw(10) << nck_name << endl;
		i++; index++;
	}
	
	cout << endl;
}