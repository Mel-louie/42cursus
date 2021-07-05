/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:51:06 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/11 15:11:39 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(char n)
{
	if (n < '0' && n > '9')
		return (-1);
	return (0);
}

int	ft_isnumber(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if ((n[i] < '0' || n[i] > '9') && n[i] != '-' && n[i] != '+')
			return (-1);
		i++;
	}
	return (0);
}
