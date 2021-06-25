/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:20:50 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 17:06:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		close_window(mlx);
	if (key == KEY_W)
		mlx->pl.posy -= 1;
	if (key == KEY_S)
		mlx->pl.posy += 1;
	if (key == KEY_A)
		mlx->pl.posx -= 1;
	if (key == KEY_D)
		mlx->pl.posx += 1;
	return (0);
}
