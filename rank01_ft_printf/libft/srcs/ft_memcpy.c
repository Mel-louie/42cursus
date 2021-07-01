/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:42:19 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 13:05:39 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*m;
	char	*l;

	if ((dst == NULL) && (src == NULL))
		return (0);
	m = (char*)dst;
	l = (char*)src;
	while (n--)
		*m++ = *l++;
	return (dst);
}
