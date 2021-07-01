/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:57:07 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 02:59:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	is_an_exit(t_mlx *mlx, int dy, int dx)
{
	t_elem_exit	*elem;

	mlx->pl.old_posx = mlx->pl.posx;
	mlx->pl.old_posy = mlx->pl.posy;
	update_pl_pos(mlx, dy, dx);
	elem = mlx->lst_exit.first;
	while (elem)
	{
		if (mlx->pl.posy == elem->exity && mlx->pl.posx == elem->exitx)
		{
			if (colect_all(mlx) == 1)
			{
				mlx->won = 42;
				return ;
			}
		}
		elem = elem->next;
	}
}

void	push_to_lst_exits(t_mlx *mlx, int y, int x)
{
	t_elem_exit	*elem;
	t_elem_exit	*tmp;

	elem = malloc(sizeof(t_elem_exit));
	if (!elem)
		close_error(mlx, ER_MEMORY);
	elem->exity = y;
	elem->exitx = x;
	if (!mlx->lst_exit.first)
	{
		elem->next = NULL;
		mlx->lst_exit.first = elem;
		return ;
	}
	tmp = mlx->lst_exit.first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}

t_elem_exit	*get_exits(t_mlx *mlx, int y, int x)
{
	t_elem_exit	*elem;

	elem = mlx->lst_exit.first;
	while (elem)
	{
		if (elem->exity == y && elem->exitx == x)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
