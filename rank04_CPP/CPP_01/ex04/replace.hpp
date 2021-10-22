/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:29:41 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 12:22:04 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

void	strReplace(std::string& content, std::string s1, std::string s2);

void	displayUsages();
int	checkArgs(int ac, char **av);
int	openFile(std::string fileName);
std::string	getBuffer(std::string fileName);

#endif
