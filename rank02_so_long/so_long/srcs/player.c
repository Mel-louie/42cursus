/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:45:56 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 18:42:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_player_move(t_mlx *mlx, int dy, int dx)
{
	int	new_posx;
	int	new_posy;

	new_posy = mlx->pl.posy + dy;
	new_posx = mlx->pl.posx + dx;
	if (mlx->map[new_posy][new_posx] == '1')
		return (-1);
	if (mlx->map[new_posy][new_posx] == 'C')
		return (2);
	return (1);
}

void	move_player(t_mlx *mlx, int dy, int dx)
{
	int	flag;

	flag = 0;
	if (can_player_move(mlx, dy, dx) == -1)
		flag = 1;
	else if (can_player_move(mlx, dy, dx) == 2)
		flag = 2;
	if (flag == 0)
	{
		mlx->pl.posy += dy;
		mlx->pl.posx += dx;
		if (mlx->pos.exity == mlx->pl.posy && mlx->pos.exitx == mlx->pl.posx
			&& mlx->pl.nb_to_colec <= mlx->pl.colec)
		{
			mlx->pl.posy += dy;
			mlx->pl.posx += dx;
			close_window(mlx, WON);
		}
	}
	if (flag == 2)
	{
		mlx->pl.posy += dy;
		mlx->pl.posx += dx;
		mlx->pl.colec += 1;
	}
}

void	get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->mapy / BLOCK)
	{
		x = -1;
		while (++x < mlx->mapx / BLOCK)
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->pl.posx = x;
				mlx->pl.posy = y;
			}
		}
	}
}
