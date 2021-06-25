/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_n_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:47:43 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 18:46:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawing(t_mlx *mlx, int y, int x)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_fl.ptr \
		, mlx->set.t_fl.width * x, mlx->set.t_fl.height * y);
	if (mlx->map[y][x] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_wa.ptr \
		, mlx->set.t_wa.width * x, mlx->set.t_wa.height * y);
	if (mlx->map[y][x] == 'E')
	{
		mlx->pos.exity = y;
		mlx->pos.exitx = x;
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_en.ptr \
		, mlx->set.t_en.width * x, mlx->set.t_en.height * y);
	}
	if (mlx->map[y][x] == 'C')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_co.ptr \
		, mlx->set.t_co.width * x, mlx->set.t_co.height * y);
	}
	if (y == mlx->pl.posy && x == mlx->pl.posx)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_pl.ptr \
		, mlx->set.t_pl.width * x, mlx->set.t_pl.height * y);
}

void	drawing_update(t_mlx *mlx, int y, int x)
{
	if (mlx->pl.posx == x && mlx->pl.posy == y && mlx->map[y][x] == 'C')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_fl.ptr \
		, mlx->set.t_fl.width * x, mlx->set.t_fl.height * y);
	}
}

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->mapy / BLOCK)
	{
		x = -1;
		while (++x < mlx->mapx / BLOCK)
			drawing(mlx, y, x);
	}
	y = -1;
	while (++y < mlx->mapy / BLOCK)
	{
		x = -1;
		while (++x < mlx->mapx / BLOCK)
			drawing_update(mlx, y, x);
	}
}
