/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:36:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 17:34:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_putstr_fd(EXIT_OK, 1);
	exit(0);
	return (0);
}

int	red_cross(t_mlx *mlx)
{
	close_window(mlx);
	return (0);
}
