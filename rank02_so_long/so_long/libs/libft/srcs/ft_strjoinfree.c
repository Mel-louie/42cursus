/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:08:20 by user42            #+#    #+#             */
/*   Updated: 2021/06/21 13:09:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoinfree(char *dest, char *src)
{
	char	*copy;
	int		dest_len;

	dest_len = ft_strlen(dest);
	copy = malloc(sizeof(char) * (dest_len + 1));
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, dest);
	free(dest);
	dest = malloc(sizeof(char) * (dest_len + ft_strlen(src) + 1));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	ft_strcpy(dest, copy);
	free(copy);
	ft_strcpy(dest + dest_len, src);
	return (dest);
}
