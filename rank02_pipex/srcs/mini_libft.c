/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:42:26 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/10 18:44:32 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return (char*)haystack;
	while (i < len)
	{
		if (ft_strncmp((char*)&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (0);
			return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}

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

