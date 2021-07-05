/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:12:47 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/11 20:02:12 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	handle_median(t_utils *u, int size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
				simple_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	if (size % 2 == 0)
		u->median = ((arr[size / 2] + arr[size / 2 - 1]) / 2) + 1;
	else
		u->median = (arr[size / 2]) + 1;
	u->max = arr[size - 1];
	u->min = arr[0];
}

int	set_median(t_utils *u, int size, int *stack)
{
	int	*arr;
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (0);
	while (i < size)
	{
		arr[i] = stack[i];
		i++;
	}
	handle_median(u, size, arr);
	u->arr = arr;
	free(arr);
	return (1);
}
