/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:49 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/14 14:12:44 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ClassContact.hpp"

class Phonebook
{
public:
	Phonebook();
	~Phonebook();

	void	table_of_contents(void) const;
	void	add_contact(void);
	void	search_contact(void);
	void	show_search_header(void);

private:
	Contact	contacts[8];
	int		nb_of_contacts;
};

#endif
