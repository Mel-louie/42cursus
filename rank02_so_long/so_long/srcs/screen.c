/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:07:38 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 11:30:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (is_min(mlx->mapx * 42, screenx) == 1)
		mlx->mapx *= 42;
	else
		mlx->mapx = screenx;
	if (min_val(mlx->mapy * 42, screeny) == 1)
		mlx->mapy *= 42;
	else
		mlx->mapy = screeny;
}
