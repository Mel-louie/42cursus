/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:16:28 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 12:30:31 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.phonebook.hpp"

Phonebook	add()
{
	Phonebook	new_contact;
	string	buf;

	cout << "First name: ";
	cin >> buf;
	new_contact.set_fst_name(buf);

	cout << "Last name: ";
	cin >> buf;
	new_contact.set_lst_name(buf);

	cout << "Nickname: ";
	cin >> buf;
	new_contact.set_nck_name(buf);

	cout << "Phone number: ";
	cin >> buf;
	new_contact.set_phone_num(buf);

	cout << "😈 Darkest secret: ";
	cin >> buf;
	new_contact.set_darkest_scrt(buf);

	cout << endl;

	return(new_contact);
}
