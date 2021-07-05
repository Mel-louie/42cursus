/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:59:22 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/03 18:57:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_lowest_n(t_stack *a)
{
	int	i;

	i = -1;
	if (a->stack[0] == a->min)
	{
		a->min_n = a->stack[1];
		a->pos_min_n = 1;
	}
	else
	{
		a->pos_min_n = 0;
		a->min_n = a->stack[0];
	}
	while (++i < a->size)
	{
		if (a->stack[i] < a->min_n && a->stack[i] != a->min)
		{
			a->min_n = a->stack[i];
			a->pos_min_n = i;
		}
	}
}

void	is_lowest(t_stack *a)
{
	int	i;

	i = -1;
	a->min = a->stack[0];
	a->pos_min = 0;
	while (++i < a->size)
	{
		if (a->stack[i] < a->min)
		{
			a->min = a->stack[i];
			a->pos_min = i;
		}
	}
	is_lowest_n(a);
}

void	is_biggest(t_stack *a)
{
	int	i;

	i = -1;
	a->max = a->stack[0];
	a->pos_max = 0;
	while (++i < a->size)
	{
		if (a->stack[i] > a->max)
		{
			a->max = a->stack[i];
			a->pos_max = i;
		}
	}
}

int	is_sorted_rev(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (0);
	i = a->size - 1;
	while (i > 0)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int	find_best_med(t_utils *u, t_stack *a, int size)
{
	int	pivot;
	int	x;

	if (u->min <= -250)
	{
		x = 0;
		while (x < size)
		{
			a->stack[x] = a->stack[x] + 1000;
			x++;
		}
		a->stack[x] = a->stack[x] + 1000;
	}
	if (u->max > 500)
		pivot = u->median;
	else
		pivot = get_pivot(a, size);
	return (pivot);
}
