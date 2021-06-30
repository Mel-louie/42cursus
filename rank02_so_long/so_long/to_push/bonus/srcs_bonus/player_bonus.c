/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:45:56 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 22:52:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	update_pl_pos(t_mlx *mlx, int dy, int dx)
{
	mlx->pl.posy += dy;
	mlx->pl.posx += dx;
	mlx->moves++;
}

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
	if (mlx->map[new_posy][new_posx] == 'S')
		return (3);
	return (1);
}

void	move_player_next(t_mlx *mlx, int dy, int dx, int flag)
{
	if (flag == 0)
	{
		is_an_exit(mlx, dy, dx);
	}
	if (flag == 2)
	{
		update_pl_pos(mlx, dy, dx);
		collected(mlx);
	}
	if (flag == 3)
	{
		update_pl_pos(mlx, dy, dx);
		mlx->lose = 420;
	}
}

void	move_player(t_mlx *mlx, int dy, int dx)
{
	int	flag;

	flag = 0;
	if (can_player_move(mlx, dy, dx) == -1)
		flag = 1;
	else if (can_player_move(mlx, dy, dx) == 2)
		flag = 2;
	else if (can_player_move(mlx, dy, dx) == 3)
		flag = 3;
	move_player_next(mlx, dy, dx, flag);
}

void	get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mlx->mapy / MULTIPLE)
	{
		x = -1;
		while (++x < mlx->mapx / MULTIPLE)
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->pl.posx = x;
				mlx->pl.posy = y;
			}
		}
	}
}
