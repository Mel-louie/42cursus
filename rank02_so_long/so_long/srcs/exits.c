/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:36:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 16:48:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/so_long.h"

int	close_window(t_mlx *mlx)
{
//	if (mlx->save == 0)
//	{
	mlx_destroy_window(mlx->ptr, mlx->win);
	//	clear_window(mlx);
//	}
	ft_putstr_fd(EXIT_OK, 1);
	exit(0);
	return (0);
}


int	red_cross(t_mlx *mlx)
{
	close_window(mlx);
	return (0);
}
