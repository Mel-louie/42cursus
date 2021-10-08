/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louie <louie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:49 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 18:21:05 by louie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Phonebook
{
private:
	Contact	contacts[8];
	int		nb_of_contacts;
public:
	Phonebook();
	virtual ~Phonebook();

	void	table_of_contents(void);
	void	add_contact(void);
	void	search_contact(void);
	void	show_search_header(void);
};

#endif
