/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:36:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 21:46:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_assets(t_assets *set)
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
}

void	free_lst(t_lst_colec *lst, t_lst_exit *lst_ex)
{
	t_elem_colec	*elem;
	t_elem_colec	*next;
	t_elem_exit		*elem_ex;
	t_elem_exit		*next_ex;

	if (!lst)
		return ;
	elem = lst->first;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	if (!lst_ex)
		return ;
	elem_ex = lst_ex->first;
	while (elem_ex)
	{
		next_ex = elem_ex->next;
		free(elem_ex);
		elem_ex = next_ex;
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
	free_lst(&mlx->lst_colec, &mlx->lst_exit);
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
		free_map(mlx);
}
