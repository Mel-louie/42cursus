/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:41:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/06 13:17:38 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	main(int ac, char **av)
{
	(void)ac;
	ft_putstr_fd(av[1], 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
