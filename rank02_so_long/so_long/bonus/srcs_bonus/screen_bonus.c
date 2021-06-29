/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:07:38 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 16:09:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	min_val(int val1, int val2)
{
	if (val1 < val2)
		return (1);
	else
		return (2);
}

void	window_size(t_mlx *mlx)
{
	int	screenx;
	int	screeny;

	mlx_get_screen_size(mlx->ptr, &screenx, &screeny);
	if (min_val(mlx->mapx * MULTIPLE, screenx) == 1)
		mlx->mapx *= MULTIPLE;
	else
		mlx->mapx = screenx;
	if (min_val(mlx->mapy * MULTIPLE, screeny) == 1)
		mlx->mapy *= MULTIPLE;
	else
		mlx->mapy = screeny;
}
