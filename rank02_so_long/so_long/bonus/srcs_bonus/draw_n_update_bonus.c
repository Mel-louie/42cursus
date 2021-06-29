/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_n_update_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:47:43 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 17:54:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	drawing_colec_n_enemies(t_mlx *mlx, int y, int x)
{
	t_elem_colec	*elem_c;
	t_elem_enemy	*elem_e;

	if (mlx->map[y][x] == 'C')
	{
		push_to_lst(mlx, y, x);
		elem_c = get_colectibles(mlx, y, x);
		if (elem_c && elem_c->touched == 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_co.ptr \
			, mlx->set.t_co.width * x, mlx->set.t_co.height * y);
	}
	if (mlx->map[y][x] == 'S')
	{
		push_to_lst_enemies(mlx, y, x);
		elem_e = get_enemies(mlx, y, x);
		if (elem_e && elem_e->touched == 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_enem.ptr \
			, mlx->set.t_enem.width * x, mlx->set.t_enem.height * y);
	}
}

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
	drawing_colec_n_enemies(mlx, y, x);
	if (y == mlx->pl.posy && x == mlx->pl.posx)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->set.t_pl.ptr \
		, mlx->set.t_pl.width * x, mlx->set.t_pl.height * y);
}

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	if (mlx->won != 42 && mlx->lose != 420)
	{
		while (++y < mlx->mapy / MULTIPLE)
		{
			x = -1;
			while (++x < mlx->mapx / MULTIPLE)
				drawing(mlx, y, x);
		}
	}
	else if (mlx->won == 42 && mlx->lose != 420)
		victory(mlx);
	else if (mlx->won != 42 && mlx->lose == 420)
		defeat(mlx);
}
