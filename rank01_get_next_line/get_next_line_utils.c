/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:59:23 by mdesfont          #+#    #+#             */
/*   Updated: 2019/12/16 14:23:21 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (gnl_strlen(src));
	i = 0;
	j = 0;
	if (!src)
		return (0);
	if (src == NULL || dst == NULL)
		return (0);
	while (src[j] != '\0')
		j++;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

	char		*gnl_strjoin(char const *s1, char const *s2)
	{

	char	*dest;
	size_t	len;
	int		i;

	if (s1 == NULL || s2 == NULL)
	return (NULL);
	len = ((gnl_strlen(s1)) + (gnl_strlen(s2)));
	if (!(dest = malloc(sizeof(char) * len + 1)))
	return (NULL);
	i = 0;
	while (len > 0)
	{
	if (*s1 != '\0')
	dest[i++] = *s1++;
	if (*s1 == '\0')
	{
	while (*s2 != 0)
	dest[i++] = *s2++;
	break ;
	}
	len--;
	}
	dest[i] = '\0';
//	free(s1);
s1 = dest;/*
char	*dest;
char	*m;
char	*n;
int		i;

i = 0;
m = (char*)s1;
n = (char*)s2;
if ((s1 == NULL) || (s2 == NULL))
return (NULL);
if (!(dest = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1))))
return (NULL);
ft_destjoin(m, n, dest);*/
return (dest);
}

char		*gnl_strdup(const char *s1)
{
	char *resultat;

	resultat = malloc(sizeof(char) * (gnl_strlen(s1) + 1));
	if (!resultat)
		return (0);
	ft_strlcpy(resultat, s1, gnl_strlen(s1) + 1);
	return (resultat);
}

char		*gnl_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (s == NULL)
		return (gnl_strdup(""));
	if (start > gnl_strlen(s))
		return (gnl_strdup(""));
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len && s[start] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
