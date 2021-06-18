/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:39:29 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 14:01:23 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && x < mlx->set.res_x && y >= 0 && y < mlx->set.res_y)
		(mlx->img.data)[y * mlx->set.res_x + x] = color;
}

int		rgb(int r, int g, int b, int t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	vertical_line(t_mlx *mlx, int x, t_pos_img limits, int color)
{
	while (limits.x < limits.y)
	{
		my_pixel(mlx, x, limits.x, color);
		limits.x++;
	}
}

int		try_open(char *file)
{
	int ret;

	if ((ret = open(file, O_RDONLY)) == -1)
		return (0);
	close(ret);
	return (1);
}
