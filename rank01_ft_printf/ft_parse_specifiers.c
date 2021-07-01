/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:44:04 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/21 19:08:29 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_parse_specifiers(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->specifiers[i] != '\0')
	{
		if (tab->specifiers[i] == tab->f_t[tab->i])
			tab->specifiers_flags = tab->specifiers[i];
		i++;
	}
	return (tab);
}
