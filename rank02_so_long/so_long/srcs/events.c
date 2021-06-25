/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:20:50 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 17:36:18 by user42           ###   ########.fr       */
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
	return (1);
}

void	move_player(t_mlx *mlx, int dy, int dx)
{
	int	flag;

	flag = 0;
	if (can_player_move(mlx, dy, dx) == -1)
		flag = 1;
	if (flag == 0)
	{
		mlx->pl.posy += dy;
		mlx->pl.posx += dx;
	}
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(mlx);
	if (key == KEY_W)
	{
		mlx->pl.direction = UP;
		move_player(mlx, -1, 0);
	}
	if (key == KEY_S)
	{
		mlx->pl.direction = DOWN;
		move_player(mlx, 1, 0);
	}
	if (key == KEY_A)
	{
		mlx->pl.direction = LEFT;
		move_player(mlx, 0, -1);
	}
	if (key == KEY_D)
	{
		mlx->pl.direction = RIGHT;
		move_player(mlx, 0, 1);
	}
	return (0);
}
