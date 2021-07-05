/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_supersmall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:47:15 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/14 15:47:42 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Sort 3 elements in 1 or 2 instructions
*/

void	sort_three_num(t_stack *a)
{
	if (a->stack[0] > a->stack[1] && a->stack[2] > a->stack[0])
		instructions("sa", a, NULL);
	if (a->stack[0] > a->stack[2] && a->stack[1] > a->stack[0])
		instructions("rra", a, NULL);
	if (a->stack[0] > a->stack[1] && a->stack[2] > a->stack[1])
		instructions("ra", a, NULL);
	if (a->stack[1] > a->stack[2] && a->stack[2] > a->stack[0])
	{
		instructions("sa", a, NULL);
		instructions("ra", a, NULL);
	}
	if (a->stack[1] > a->stack[2] && a->stack[0] > a->stack[1])
	{
		instructions("sa", a, NULL);
		instructions("rra", a, NULL);
	}
}

/*
** Sort 50 elements max
** Prendre l'index du plus petit nombre de la stack;
** Vérifier s'il est dans la première ou dans la 2ème
** partie de la stack;
** Si 1, ra tous les nb au dessus de lui jusqu'à ce
** qu'il soit en tête de liste;
** Si 2, remonter tous les nb jusqu'à ce qu'il soit en
** dernière position et le remonter;
** Push sur stack b;
** Quand il n'en reste que 3 dans a, tri de 3;
** Push tout b dans a
*/

void	sort_five_num(t_stack *a, t_stack *b)
{
	int	index;

	index = 0;
	while (a->size > 3)
	{
		index = get_position(a->stack, a->size, get_min(a->stack, a->size));
		if (index < a->size / 2)
			while (index--)
				instructions("ra", a, b);
		else
			while (index++ < a->size)
				instructions("rra", a, b);
		instructions("pb", a, b);
	}
	sort_three_num(a);
	while (b->size)
		instructions("pa", a, b);
}
