/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/19 17:18:35 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "replace.hpp"

void	strReplace(std::string& content, std::string s1, std::string s2)
{
	std::size_t	toErase = s1.length(); 
	std::size_t	newIndex = s2.length();
	std::size_t	position = content.find(s1);

	while (position != std::string::npos)
	{
		content.erase(position, toErase);
		content.insert(position, s2);
		position = content.find( s1, position + newIndex);
	}
}
