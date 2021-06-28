/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:58 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/28 22:51:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*new_string(char *str, long nb, long len, long sign)
{
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign < 0)
		str[len++] = '-';
	return (str);
}

int	n_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;
	long	nb;
	long	sign;

	nb = n;
	sign = 1;
	len = (long)n_size(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb < 0)
	{
		nb = -nb;
		sign = -sign;
	}
	str = malloc(sizeof(char) * (len + 1));
	str = new_string(str, nb, len, sign);
	return (str);
}
