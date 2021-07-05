/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:43 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/14 14:42:28 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *a, t_stack *b, int swap)
{
	int		tmp;

	tmp = 0;
	if (swap == 0 || swap == 2)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = tmp;
	}
	if (swap == 1 || swap == 2)
	{
		tmp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = tmp;
	}
}

int	*process_rotate(int *stack, int size)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (NULL);
	if (size > 1)
	{
		tmp[size - 1] = stack[i];
		while (i < (size - 1))
		{
			tmp[i] = stack[i + 1];
			i++;
		}
		stack = free_stack(stack);
		stack = tmp;
	}
	return (stack);
}

int	ft_rotate(t_stack *a, t_stack *b, int ro)
{
	if (ro == 0 || ro == 2)
		a->stack = process_rotate(a->stack, a->size);
	if (ro == 1 || ro == 2)
		b->stack = process_rotate(b->stack, b->size);
	return (0);
}

int	*process_rerotate(int *stack, int size)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (NULL);
	if (size > 1)
	{
		tmp[i] = stack[size - 1];
		i++;
		while (i < size)
		{
			tmp[i] = stack[i - 1];
			i++;
		}
		stack = free_stack(stack);
		stack = tmp;
	}
	return (stack);
}

int	ft_revrotate(t_stack *a, t_stack *b, int rro)
{
	if (rro == 0 || rro == 2)
		a->stack = process_rerotate(a->stack, a->size);
	if (rro == 1 || rro == 2)
		b->stack = process_rerotate(b->stack, b->size);
	return (0);
}
