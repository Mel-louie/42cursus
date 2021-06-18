/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:43:08 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 14:07:06 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	move forward if no wall in front of you then,
**	move backward if no wall in front of you
*/

void	move_forward(t_mlx *mlx)
{
	double move_speed;

	move_speed = 0.09;
	if (mlx->set.map[(int)(mlx->game.player.x + mlx->game.player_direction.x \
		* move_speed)][(int)mlx->game.player.y] == '0')
		mlx->game.player.x += mlx->game.player_direction.x * move_speed;
	if (mlx->set.map[(int)mlx->game.player.x][(int)(mlx->game.player.y \
			+ mlx->game.player_direction.y * move_speed)] == '0')
		mlx->game.player.y += mlx->game.player_direction.y * move_speed;
}

void	move_backward(t_mlx *mlx)
{
	double move_speed;

	move_speed = 0.09;
	if (mlx->set.map[(int)(mlx->game.player.x - mlx->game.player_direction.x \
			* move_speed)][(int)mlx->game.player.y] == '0')
		mlx->game.player.x -= mlx->game.player_direction.x * move_speed;
	if (mlx->set.map[(int)mlx->game.player.x][(int)(mlx->game.player.y \
			- mlx->game.player_direction.y * move_speed)] == '0')
		mlx->game.player.y -= mlx->game.player_direction.y * move_speed;
}

/*
**	move to the right then,
**	move to the left
*/

void	move_right(t_mlx *mlx)
{
	double move_speed;

	move_speed = 0.09;
	if (mlx->set.map[(int)(mlx->game.player.x + mlx->game.plane.x \
			* move_speed)][(int)mlx->game.player.y] == '0')
		mlx->game.player.x += mlx->game.plane.x * move_speed;
	if (mlx->set.map[(int)mlx->game.player.x][(int)(mlx->game.player.y \
			+ mlx->game.plane.y * move_speed)] == '0')
		mlx->game.player.y += mlx->game.plane.y * move_speed;
}

void	move_left(t_mlx *mlx)
{
	double move_speed;

	move_speed = 0.09;
	if (mlx->set.map[(int)(mlx->game.player.x - mlx->game.plane.x \
		* move_speed)][(int)mlx->game.player.y] == '0')
		mlx->game.player.x -= mlx->game.plane.x * move_speed;
	if (mlx->set.map[(int)mlx->game.player.x][(int)(mlx->game.player.y \
		- mlx->game.plane.y * move_speed)] == '0')
		mlx->game.player.y -= mlx->game.plane.y * move_speed;
}
