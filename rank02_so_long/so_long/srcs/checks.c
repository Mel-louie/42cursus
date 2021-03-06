/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:04:53 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 02:04:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_char(t_mlx *mlx)
{
	if (mlx->e == 0)
		close_error(mlx, ER_NO_EX);
	if (mlx->p == 0)
		close_error(mlx, ER_NO_PL);
	if (mlx->c == 0)
		close_error(mlx, ER_NO_CO);
}

int	is_ok_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	check_ext(char *file_ext, char *ext)
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
