/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:22:28 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 09:25:57 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub;
	unsigned int	len_str;

	if (!s || !len)
		return (NULL);
	i = 0;
	len_str = ft_strlen(s);
	if (len_str < start)
		return (ft_strdup(""));
	if (!(sub = malloc(sizeof(char) * len + 1)))
		return (0);
	while (s[start] && i < len)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
