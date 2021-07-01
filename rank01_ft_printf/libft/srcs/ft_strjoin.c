/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:16:49 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 13:06:38 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	ft_destjoin(char *m, char *n, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m[i])
	{
		dest[i] = m[i];
		i++;
	}
	while (n[j])
	{
		dest[i] = n[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (*dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*m;
	char	*n;

	m = (char*)s1;
	n = (char*)s2;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_destjoin(m, n, dest);
	return (dest);
}
