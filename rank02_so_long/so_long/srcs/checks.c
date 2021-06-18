/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:04:53 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 20:05:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		check_ext(char *file_ext, char *ext)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file_ext);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (file_ext[len_file] != ext[len_ext])
			return (-1);
		len_file--;
		len_ext--;
	}
	return (0);
}
