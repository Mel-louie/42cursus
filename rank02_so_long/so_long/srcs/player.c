/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:45:56 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 21:38:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_pl_pos(t_mlx *mlx, int dy, int dx)
{
	mlx->pl.posy += dy;
	mlx->pl.posx += dx;
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
	return (1);
}

void	display_moves(t_mlx *mlx)
{
	char	*str;

	mlx->moves++;
	str = ft_itoa(mlx->moves);
	ft_putstr_fd("\033[1;37mSO_LONG 🐟\t", 1);
	ft_putstr_fd("\033[0;37mmovement \033[1;37m#", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	str = free_str(str);
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
		is_an_exit(mlx, dy, dx);
		display_moves(mlx);
	}
	if (flag == 2)
	{
		update_pl_pos(mlx, dy, dx);
		collected(mlx);
		display_moves(mlx);
	}
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
