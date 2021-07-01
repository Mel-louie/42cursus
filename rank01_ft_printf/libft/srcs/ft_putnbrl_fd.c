/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:52:38 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 12:52:40 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbrl_fd(long long n, int fd)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putstr_fd("-9223372036854775808", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbrl_fd(n * (-1), fd);
	}
	else if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbrl_fd(n / 10, fd);
		ft_putnbrl_fd(n % 10, fd);
	}
}
