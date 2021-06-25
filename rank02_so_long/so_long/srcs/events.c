/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:20:50 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 16:05:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(mlx);
	get_player_pos(mlx);
	printf("player %i", mlx->pl.posx);
	printf(" %i\n", mlx->pl.posy);
//	if (key == KEY_W)
		
	return (0);
}
