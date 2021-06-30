/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:54:34 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 21:16:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	push_to_lst_enemies(t_mlx *mlx, int y, int x)
{
	t_elem_enemy	*elem;
	t_elem_enemy	*tmp;

	elem = malloc(sizeof(t_elem_enemy));
	if (!elem)
		close_error(mlx, ER_MEMORY);
	elem->enemyy = y;
	elem->enemyx = x;
	elem->touched = 0;
	if (!mlx->lst_enemy.first)
	{
		elem->next = NULL;
		mlx->lst_enemy.first = elem;
		return ;
	}
	tmp = mlx->lst_enemy.first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}

t_elem_enemy	*get_enemies(t_mlx *mlx, int y, int x)
{
	t_elem_enemy	*elem;

	elem = mlx->lst_enemy.first;
	while (elem)
	{
		if (elem->enemyy == y && elem->enemyx == x)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

void	defeat(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_string_put(mlx->ptr, mlx->win, (mlx->mapx / 2) - 100,
		(mlx->mapy / 2) - 50, 0x00FF0000,
		"Oh no, that was a shark, you're dead :(");
	mlx_string_put(mlx->ptr, mlx->win, (mlx->mapx / 2) - 50,
		(mlx->mapy / 2) - 10, 0x00FF0000,
		"Press ESC to exit.");
}
