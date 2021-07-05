/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:35 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/14 15:57:02 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**
*/

void	positions_min_max(t_stack *b)
{
	is_biggest(b);
	b->pos_min = get_position(b->stack, b->size, get_min(b->stack, b->size));
}

void	sort_b_hundred(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		positions_min_max(b);
		if (b->size + b->pos_min < b->size + b->pos_max)
		{
			if (b->pos_min < b->size / 2)
				while (b->pos_min--)
					instructions("rb", a, b);
			else
				while (b->stack[0] != get_min(b->stack, b->size))
					instructions("rrb", a, b);
			instructions("pa", a, b);
			instructions("ra", a, b);
		}
		else if (b->size + b->pos_min >= b->size + b->pos_max && b->size)
		{
			if (b->pos_max < b->size / 2)
				while (b->pos_max--)
					instructions("rb", a, b);
			else
				while (b->stack[0] != b->max)
					instructions("rrb", a, b);
			instructions("pa", a, b);
		}
	}
}

/*
**
*/

void	push_to_b(t_stack *a, t_stack *b, t_utils *u)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < a->size)
	{
		if (flag == 1)
			break ;
		if (a->stack[0] <= u->arr_med)
		{
			if (a->stack[0] == u->arr_end)
				flag = 1;
			instructions("pb", a, b);
			i--;
		}
		if (a->stack[0] > u->arr_med)
		{
			if (a->stack[0] == u->arr_end)
				flag = 1;
			instructions("ra", a, b);
		}
	}
}

void	sort_hundred(t_stack *a, t_stack *b, t_utils *u)
{
	set_median(u, a->size, a->stack);
	u->arr_min = u->min;
	u->arr_med = u->median;
	u->arr_end = a->stack[a->size - 1];
	push_to_b(a, b, u);
	sort_b_hundred(a, b);
	while (a->stack[0] <= u->arr_med)
		instructions("ra", a, b);
	while (a->stack[0] > u->arr_med)
		instructions("pb", a, b);
	sort_b_hundred(a, b);
	while (a->stack[0] > u->arr_min)
		instructions("ra", a, b);
}
