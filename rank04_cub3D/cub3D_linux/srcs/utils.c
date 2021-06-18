/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:55:34 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 12:40:15 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int				red_cross(t_mlx *mlx)
{
	close_window(mlx, 0);
	return (0);
}

t_vector_dir	dir_vec(double x, double y)
{
	t_vector_dir vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_pos_img		img_pos_vec(int x, int y)
{
	t_pos_img vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

void			init_screen(t_mlx *mlx, int screen_x, int screen_y)
{
	if (mlx->save == 0)
	{
		mlx->set.res_x = fmin(mlx->set.res_x, screen_x);
		mlx->set.res_y = fmin(mlx->set.res_y, screen_y);
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
		mlx->set.res_x, mlx->set.res_y, WIN_NAME);
	}
	if (mlx->save == 1)
	{
		mlx->set.res_x = fmin(mlx->set.res_x, 11000);
		mlx->set.res_y = fmin(mlx->set.res_y, 6187);
	}
}
