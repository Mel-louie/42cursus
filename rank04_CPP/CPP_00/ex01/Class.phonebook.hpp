/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:05:08 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/08 14:24:19 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_CPP
# define CLASS_PHONEBOOK_CPP

# define MAX_CONTACT 8
# define MAX_WIDTH 10

# include "Class.contact.hpp"

class Phonebook
{
public:
	Phonebook(void);
	~Phonebook(void);
	void	table_of_contents(void);
	
private:
	Contact contact[8];
    int nb_contact;
    void	add();
    void	search();
};

#endif
