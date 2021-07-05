/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:27 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/03 18:57:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	five_hundred_stack_a_end(t_stack *a, t_stack *b)
{
	int	i;

	i = b->size;
	while (i > 0)
	{
		instructions("pa", a, b);
		i--;
	}
}

void	five_hundred_stack_a(t_stack *a, t_stack *b, int i)
{
	while (i > 0)
	{
		while (a->stack[0] != a->min && is_sorted(a, a->size) == 1)
		{
			if (a->pos_min_n == 0 && a->pos_min == 1)
				instructions("sa", a, b);
			else if (a->pos_min <= a->size / 2)
				instructions("ra", a, b);
			else
				instructions("rra", a, b);
		}
		instructions("pb", a, b);
		i--;
		is_lowest(a);
		is_biggest(a);
		if (a->size == 2 && a->stack[0] == a->max
			&& a->stack[1] == a->min)
		{
			instructions("sa", a, b);
			break ;
		}
		if (is_sorted(a, a->size) == 0 && is_sorted_rev(b) == 0)
			break ;
	}
	five_hundred_stack_a_end(a, b);
}

void	opti_b(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		is_biggest(b);
		if (b->size / 2 > b->pos_max)
			while (b->stack[0] != b->max)
				instructions("rb", a, b);
		else
			while (b->stack[0] != b->max)
				instructions("rrb", a, b);
		instructions("pa", a, b);
	}
}

void	part_and_sort(t_stack *a, t_stack *b, int size, t_utils *u)
{
	int	ra;
	int	pivot;
	int	i;

	ra = 0;
	i = 0;
	pivot = find_best_med(u, a, size);
	while (i < size)
	{
		if (a->stack[0] <= pivot)
			instructions("pb", a, b);
		else
		{
			instructions("ra", a, b);
			ra++;
		}
		i++;
	}
	while (ra-- && a->flag == 1)
		instructions("rra", a, b);
	if (b->size <= a->size / 4)
		opti_b(a, b);
	if (a->flag == 0)
		a->flag = 1;
}

void	quicksort_five_hundred(t_stack *a, t_stack *b, t_utils *u, int size)
{
	int	i;

	i = 0;
	if (is_sorted(a, size) == 0)
	{
		while (i < size)
		{
			instructions("ra", a, b);
			i++;
		}
		return ;
	}
	is_lowest(a);
	is_biggest(a);
	set_median(u, size, a->stack);
	part_and_sort(a, b, size, u);
	while (b->size != 0)
		instructions("pa", a, b);
	quicksort_five_hundred(a, b, u, size / 2);
	if (size % 2 != 0)
		size++;
	quicksort_five_hundred(a, b, u, size / 2);
}
