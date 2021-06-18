/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:37:30 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 09:25:57 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char*)src)[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
