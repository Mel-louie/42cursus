/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinitialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:32:47 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 13:57:40 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_reinitialize(t_tab *tab)
{
	tab->specifiers_flags = '\0';
	tab->convert[0] = '\0';
	tab->convert[1] = '\0';
	tab->convert[2] = '\0';
	tab->convert[3] = '\0';
	tab->convert[4] = '\0';
	tab->convert[5] = '\0';
	tab->convert[6] = '\0';
	tab->precision = -1;
	tab->widht = 0;
	return (tab);
}
