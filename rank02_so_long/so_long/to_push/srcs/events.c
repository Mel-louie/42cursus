/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:20:50 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 22:35:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(mlx, EXIT_OK);
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
