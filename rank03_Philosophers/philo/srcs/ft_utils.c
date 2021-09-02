/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:40:12 by louielouie        #+#    #+#             */
/*   Updated: 2021/09/02 16:16:11 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	size_t	big;
	int		res;
	char	sign;

	big = 0;
	sign = '+';
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = *str;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		big = big * 10 + (*str - 48);
		str++;
	}
	res = big;
	if (sign == '-')
		return (-res);
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	alloc_error(int code)
{
	printf("Error on memory allocation.\n");
	return (code);
}
