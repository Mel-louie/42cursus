/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:51:12 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/11 14:51:13 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * n + 1);
	if (str == NULL)
	{
		free(str);
		return (0);
	}
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[n] = '\0';
	return (str);
}

static int	ft_countwords(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			word++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (word);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	char	**s;
	int		k;

	i = 0;
	k = 0;
	if (str == NULL)
		return (NULL);
	s = malloc(sizeof(s) * (ft_countwords(str, c) + 1));
	if (s == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
			s[k++] = ft_strndup(str + j, i - j);
	}
	s[k] = 0;
	return (s);
}
