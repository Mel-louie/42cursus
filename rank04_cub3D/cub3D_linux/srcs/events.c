/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:54:17 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/09 14:04:01 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		close_window(mlx, 0);
	if (keycode == KEY_W)
		move_forward(mlx);
	if (keycode == KEY_UP)
		move_forward(mlx);
	if (keycode == KEY_A)
		move_left(mlx);
	if (keycode == KEY_S)
		move_backward(mlx);
	if (keycode == KEY_DW)
		move_backward(mlx);
	if (keycode == KEY_D)
		move_right(mlx);
	if (keycode == KEY_RIGHT)
		rotate_right(mlx);
	if (keycode == KEY_LEFT)
		rotate_left(mlx);
	return (0);
}

int		close_window(t_mlx *mlx, int code)
{
	if (mlx->save == 0)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		clear_window(mlx);
	}
	if (code == 0)
		ft_putstr_fd(OK_CODE, 1);
	else if (code == 1)
	{
		clear_window(mlx);
		ft_putstr_fd(OK_SCREEN, 1);
	}
	exit(0);
	return (0);
}

int		close_error(t_mlx *mlx, char *error, void *ft_free, void (*f)(char**))
{
	clear_window(mlx);
	ft_putstr_fd(error, 2);
	if (ft_free && f)
		(*f)(ft_free);
	exit(0);
	return (0);
}

void	rotate_right(t_mlx *mlx)
{
	double rot_speed;
	double old_dir_x;
	double old_plane_x;

	rot_speed = 0.03;
	old_dir_x = mlx->game.player_direction.x;
	mlx->game.player_direction.x = mlx->game.player_direction.x \
		* cos(-rot_speed) - mlx->game.player_direction.y * sin(-rot_speed);
	mlx->game.player_direction.y = old_dir_x * sin(-rot_speed) \
		+ mlx->game.player_direction.y * cos(-rot_speed);
	old_plane_x = mlx->game.plane.x;
	mlx->game.plane.x = mlx->game.plane.x * cos(-rot_speed) \
		- mlx->game.plane.y * sin(-rot_speed);
	mlx->game.plane.y = old_plane_x * sin(-rot_speed) \
		+ mlx->game.plane.y * cos(-rot_speed);
}

void	rotate_left(t_mlx *mlx)
{
	double rot_speed;
	double old_dir_x;
	double old_plane_x;

	rot_speed = -0.03;
	old_dir_x = mlx->game.player_direction.x;
	mlx->game.player_direction.x = mlx->game.player_direction.x \
		* cos(-rot_speed) - mlx->game.player_direction.y * sin(-rot_speed);
	mlx->game.player_direction.y = old_dir_x * sin(-rot_speed) \
		+ mlx->game.player_direction.y * cos(-rot_speed);
	old_plane_x = mlx->game.plane.x;
	mlx->game.plane.x = mlx->game.plane.x * cos(-rot_speed) \
		- mlx->game.plane.y * sin(-rot_speed);
	mlx->game.plane.y = old_plane_x * sin(-rot_speed) + mlx->game.plane.y \
		* cos(-rot_speed);
}
