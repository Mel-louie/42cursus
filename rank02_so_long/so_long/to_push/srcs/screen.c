/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:07:38 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 20:33:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	window_size(t_mlx *mlx)
{
	int	screenx;
	int	screeny;

	mlx_get_screen_size(mlx->ptr, &screenx, &screeny);
	if (mlx->mapx * MULTIPLE > screenx)
		close_error(mlx, "Error\n\033[1;34mThe map is to big for the screen.\n");
	else
		mlx->mapx *= MULTIPLE;
	if (mlx->mapy * MULTIPLE > screeny)
		close_error(mlx, "Error\n\033[1;34mThe map is to big for the screen.\n");
	else
		mlx->mapy *= MULTIPLE;
}
