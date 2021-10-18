/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:29:41 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 17:44:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

void	displayUsages();
int	checkArgs(int ac, char **av, std::string replaceFilename);
std::string	getBuffer(std::string fileName);

#endif
