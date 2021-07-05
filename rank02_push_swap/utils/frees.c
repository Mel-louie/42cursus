/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:50:53 by mdesfont          #+#    #+#             */
/*   Updated: 2021/06/11 15:08:05 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*free_stack(int *stack)
{
	if (stack)
		free(stack);
	return (NULL);
}

void	*free_str(char *s)
{
	if (s)
		free(s);
	return (NULL);
}
