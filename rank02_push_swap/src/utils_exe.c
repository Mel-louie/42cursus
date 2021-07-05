/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:50 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/03 18:41:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(int *stack, int len)
{
	int	min;
	int	i;

	i = 0;
	if (!stack)
		return (0);
	min = stack[i];
	while (i < len)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	get_position(int *stack, int len, int nb)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (stack[index] == nb)
			return (index);
		index++;
	}
	return (0);
}

int	get_pivot(t_stack *a, int size)
{
	int	i;
	int	j;
	int	sum;

	i = -1;
	j = -1;
	sum = 0;
	while (++j != size)
		sum += a->stack[++i];
	return (sum / size);
}

int	is_sorted(t_stack *a, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (0);
	while (i < size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(int len, char **tab, int i, int j)
{
	while (i < len)
	{
		while (j < len)
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
