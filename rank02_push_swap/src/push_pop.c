/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:41:32 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/14 15:03:14 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** 3. if stack size == 1 num, realloc it with he good size and pass it tmp_push
**		else, create a new tab with the good size (push->size++), give it
**		tmp_push for [0] and pass it the old push begin with tmp[1]
** 4. swap tmp stack with stack push
*/

int	push_next(t_stack *push, int *tmp, int tmp_push, int i)
{
	if (push->size == 1)
	{
		push->stack = free_stack(push->stack);
		push->stack = malloc(sizeof(int) * push->size);
		if (push->stack == NULL)
			return (-1);
		push->stack[0] = tmp_push;
	}
	else
	{
		tmp = malloc(sizeof(int) * push->size);
		if (tmp == NULL)
			return (-1);
		i = 0;
		tmp[i] = tmp_push;
		i++;
		while (i < push->size)
		{
			tmp[i] = push->stack[i - 1];
			i++;
		}
		push->stack = free_stack(push->stack);
		push->stack = tmp;
	}
	return (0);
}

/*
** 1. save [0]'s pop and futur new pop
** 2. give its value to new pop
*/

int	ft_push(t_stack *push, t_stack *pop)
{
	int		tmp_push;
	int		*tmp;
	int		i;

	i = -1;
	pop->size--;
	tmp_push = pop->stack[0];
	tmp = malloc(sizeof(int) * pop->size);
	if (tmp == NULL)
		return (-1);
	while (++i < pop->size)
		tmp[i] = pop->stack[i + 1];
	pop->stack = free_stack(pop->stack);
	pop->stack = malloc(sizeof(int) * pop->size);
	if (pop->stack == NULL)
		return (-1);
	i = -1;
	while (++i < pop->size)
		pop->stack[i] = tmp[i];
	tmp = free_stack(tmp);
	push->size++;
	if (push_next(push, tmp, tmp_push, i) == -1)
		return (-1);
	return (0);
}
