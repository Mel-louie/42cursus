/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:36:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 23:04:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	free_assets(t_assets *set)
{
	if (set->path_co)
		free(set->path_co);
	if (set->path_en)
		free(set->path_en);
	if (set->path_fl)
		free(set->path_fl);
	if (set->path_pl1)
		free(set->path_pl1);
	if (set->path_pl2)
		free(set->path_pl2);
	if (set->path_pl3)
		free(set->path_pl3);
	if (set->path_pl4)
		free(set->path_pl4);
	if (set->path_wa)
		free(set->path_wa);
	if (set->path_enem)
		free(set->path_enem);
}

void	free_lst_colec(t_lst_colec *lst)
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

void	free_lst_enem(t_lst_enemy *lst)
{
	t_elem_enemy	*elem;
	t_elem_enemy	*next;

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

void	free_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->mapy / MULTIPLE)
	{
		if (mlx->map[i])
			free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

void	free_game(t_mlx *mlx)
{
	free_assets(&mlx->set);
	free_lst_colec(&mlx->lst_colec);
	free_lst_enem(&mlx->lst_enemy);
	if (mlx->set.t_co.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_co.ptr);
	if (mlx->set.t_en.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_en.ptr);
	if (mlx->set.t_fl.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_fl.ptr);
	if (mlx->set.t_pl1.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_pl1.ptr);
	if (mlx->set.t_pl2.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_pl2.ptr);
	if (mlx->set.t_pl3.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_pl3.ptr);
	if (mlx->set.t_pl4.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_pl4.ptr);
	if (mlx->set.t_wa.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_wa.ptr);
	if (mlx->set.t_enem.ptr)
		mlx_destroy_image(mlx->ptr, mlx->set.t_enem.ptr);
	if (mlx->map)
		free_map(mlx);
}
