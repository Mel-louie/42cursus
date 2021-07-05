/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:46 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/24 15:20:52 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**parse(int argc, char **argv, t_utils *u)
{
	char	**new_tab;
	char	*new_str;

	new_str = NULL;
	if (argc == 2)
	{
		new_str = ft_strdup(argv[1]);
		new_tab = ft_split(new_str, ' ');
		new_str = free_str(new_str);
		while (new_tab[u->len])
			u->len++;
		u->len++;
	}
	else
	{
		new_tab = ft_tabdup(argv + 1);
		u->len = argc;
	}
	return (new_tab);
}

int	creat_stacks(int len, char **tab, t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	a->stack = malloc(sizeof(int) * len);
	if (a->stack == NULL)
		return (-1);
	b->stack = malloc(sizeof(int) * len);
	if (b->stack == NULL)
		return (-1);
	a->size = len - 1;
	b->size = 0;
	while (i < len - 1)
	{
		a->stack[i] = ft_atoi(tab[i]);
		b->stack[i] = 0;
		i++;
	}
	return (0);
}

void	sort(t_stack *a, t_stack *b, t_utils *u)
{
	a->flag = 0;
	if (a->size == 3)
		sort_three_num(a);
	if (a->size <= 20)
		sort_five_num(a, b);
	if (a->size <= 102 && is_sorted(a, a->size) == 1)
		sort_hundred(a, b, u);
	if (is_sorted(a, a->size) == 1)
		quicksort_five_hundred(a, b, u, a->size);
	if (is_sorted(a, a->size) == 1)
		five_hundred_stack_a(a, b, a->size);
}

void	instructions(char *inst, t_stack *a, t_stack *b)
{
	if (ft_strcmp("sa", inst) == 0)
		ft_swap(a, b, 0);
	if (ft_strcmp("sb", inst) == 0)
		ft_swap(a, b, 1);
	if (ft_strcmp("ss", inst) == 0)
		ft_swap(a, b, 2);
	if (ft_strcmp("ra", inst) == 0)
		ft_rotate(a, b, 0);
	if (ft_strcmp("rb", inst) == 0)
		ft_rotate(a, b, 1);
	if (ft_strcmp("rr", inst) == 0)
		ft_rotate(a, b, 2);
	if (ft_strcmp("rra", inst) == 0)
		ft_revrotate(a, b, 0);
	if (ft_strcmp("rrb", inst) == 0)
		ft_revrotate(a, b, 1);
	if (ft_strcmp("rrr", inst) == 0)
		ft_revrotate(a, b, 2);
	if ((ft_strcmp("pa", inst) == 0) && b->size > 0)
		ft_push(a, b);
	if ((ft_strcmp("pb", inst) == 0) && a->size > 0)
		ft_push(b, a);
	ft_write_inst(inst);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_utils	u;
	char	**new_tab;

	u.len = 0;
	new_tab = parse(argc, argv, &u);
	if ((errors(u.len, new_tab, 0)) == -1 || (argc < 2))
	{
		new_tab = free_tab(new_tab);
		return (0);
	}
	creat_stacks(u.len, new_tab, &a, &b);
	if (u.len == 3 && a.stack[0] > a.stack[1])
		instructions("sa", &a, NULL);
	else if (is_sorted(&a, a.size) == 1)
		sort(&a, &b, &u);
	a.stack = free_stack(a.stack);
	b.stack = free_stack(b.stack);
	new_tab = free_tab(new_tab);
	return (0);
}
