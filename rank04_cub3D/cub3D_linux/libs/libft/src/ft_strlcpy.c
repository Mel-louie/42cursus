/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:32:21 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 09:25:57 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;

	if (src)
		len = ft_strlen(src);
	else
		len = 0;
	if (len < size && src && dst)
		ft_strncpy(dst, src, len + 1);
	else if (size != 0 && src && dst)
	{
		ft_strncpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len);
}
