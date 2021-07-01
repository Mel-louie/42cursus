/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:46:49 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:25:35 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsers(t_tab *tab)
{
	if (ft_strcmp(tab->f_copy, "%") == 0)
		return (0);
	while (tab->f_copy[tab->i] != '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			ft_reinitialize(tab);
			ft_treatments(tab);
		}
		else
		{
			write(tab->fd, &tab->f_copy[tab->i], 1);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
