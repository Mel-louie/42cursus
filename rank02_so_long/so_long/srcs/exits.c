/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:36:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 13:25:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_assets(t_assets *set, t_mlx *mlx)
{
	if (set->path_co)
		free(set->path_co);
	if (set->path_en)
		free(set->path_en);
	if (set->path_fl)
		free(set->path_fl);
	if (set->path_pl)
		free(set->path_pl);
	if (set->path_wa)
		free(set->path_wa);
(void)mlx;
}

void	free_lst(t_lst_colec *lst)
{
	t_elem_colec	*elem;
	t_elem_colec	*next;

	if (!lst)
		return ;
	elem = lst->first;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}

void	free_map(char **map, int i)
{
/*	if (!map)
		return ;
	if (i < 0)
	{
		ft_putstr_fd(ER_NOTSURR, 2);
		return ;
	}
	while (i >= 0)
	{
		if (map[i])
			free(map[i]);
		i--;
	}*/
	free(map);
	(void)i;
}

void	free_game(t_mlx *mlx)
{
	free_assets(&mlx->set, mlx);
	free_lst(&mlx->lst_colec);
	if (mlx->set.t_co.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_co.ptr);
	if (mlx->set.t_en.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_en.ptr);
	if (mlx->set.t_fl.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_fl.ptr);
	if (mlx->set.t_pl.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_pl.ptr);
	if (mlx->set.t_wa.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_wa.ptr);
	if (mlx->map)
		free_map(mlx->map, mlx->mapy);
}

int	close_error(t_mlx *mlx, char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
	return (0);
	(void)mlx;
}

int	close_window(t_mlx *mlx, char *str)
{
	if (mlx->win)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_window(mlx->ptr, mlx->win);
	}
	if (mlx->img.ptr)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	free_game(mlx);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	ft_putstr_fd(str, 1);
	exit (0);
}

int	red_cross(t_mlx *mlx)
{
	close_window(mlx, EXIT_OK);
	return (0);
}

void	victory(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_string_put(mlx->ptr, mlx->win, (mlx->mapx / 2) - 100,
		(mlx->mapy / 2) - 50, 0x00008000,
		"CONGRATS YOU WON!1!! Enjoy the fish");
	mlx_string_put(mlx->ptr, mlx->win, (mlx->mapx / 2) - 50,
		(mlx->mapy / 2) - 10, 0x00008000,
		"Press ESC to exit.");
}
