/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:37:04 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/28 11:19:58 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab			*ft_display_c(t_tab *tab)
{
	int		c;

	if (tab->f_t[tab->i - 1] == 'c')
		tab->i--;
	c = (char)va_arg(tab->arg, int);
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		ft_display_widht(tab, '0', tab->widht - 1, 1);
	else if (tab->convert[0] != '-')
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
	ft_putchar(c);
	tab->len++;
	if (tab->convert[0] == '-')
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
	return (tab);
}
