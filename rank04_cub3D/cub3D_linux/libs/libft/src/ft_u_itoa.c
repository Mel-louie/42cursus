/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:38:17 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 09:25:57 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbdigit(unsigned int n)
{
	int		len;
	int		neg;

	neg = 0;
	len = 1;
	while (n / 10 >= 1)
	{
		len++;
		n /= 10;
	}
	return (len + neg);
}

char			*ft_u_itoa(unsigned int n)
{
	char	*str;
	int		len;

	len = nbdigit(n);
	str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
