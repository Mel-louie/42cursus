/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:54:34 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 16:09:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	collected(t_mlx *mlx)
{
	t_elem_colec	*elem;

	elem = mlx->lst_colec.first;
	while (elem)
	{
		if (mlx->pl.posy == elem->colecy && mlx->pl.posx == elem->colecx)
		{
			elem->touched = 1;
			return ;
		}
		elem = elem->next;
	}
}

int	colect_all(t_mlx *mlx)
{
	t_elem_colec	*elem;
	int				len;
	int				count;

	elem = mlx->lst_colec.first;
	len = mlx->c;
	count = 0;
	while (elem)
	{
		if (elem->touched == 1)
			count++;
		elem = elem->next;
	}
	if (count == len)
		return (1);
	return (0);
}

void	push_to_lst(t_mlx *mlx, int y, int x)
{
	t_elem_colec	*elem;
	t_elem_colec	*tmp;

	elem = malloc(sizeof(t_elem_colec));
	if (!elem)
		close_error(mlx, ER_MEMORY);
	elem->colecy = y;
	elem->colecx = x;
	elem->touched = 0;
	if (!mlx->lst_colec.first)
	{
		elem->next = NULL;
		mlx->lst_colec.first = elem;
		return ;
	}
	tmp = mlx->lst_colec.first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}

t_elem_colec	*get_colectibles(t_mlx *mlx, int y, int x)
{
	t_elem_colec	*elem;

	elem = mlx->lst_colec.first;
	while (elem)
	{
		if (elem->colecy == y && elem->colecx == x)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
