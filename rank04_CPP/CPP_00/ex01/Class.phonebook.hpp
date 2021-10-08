/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:23:40 by louie             #+#    #+#             */
/*   Updated: 2021/10/08 11:15:14 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

using namespace std;

//namespace register1
//{
	class Phonebook
	{
		char    name[255];
		char    ph_num[15];
		public:
		void    get_data();
	};
//};
