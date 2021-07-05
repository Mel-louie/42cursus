/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:39 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/17 17:58:00 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	errors(int len, char **tab, int i)
{
	if (is_duplicate(len, tab, 0, 1) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	while (tab[i])
	{
		if (ft_isnumber(tab[i]) == -1 || ft_great_atoi(tab[i]) > 2147483647
			|| ft_great_atoi(tab[i]) < -2147483648 || ft_strlen(tab[i]) > 19)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}
