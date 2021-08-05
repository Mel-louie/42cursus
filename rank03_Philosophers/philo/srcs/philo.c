/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:41:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/08/05 14:58:37 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
//	char			str[500];
//	char			*curr;
//	int				total;
	t_structs		s;

	if (handle_errors(ac, av) == 1)
		return (1);
	get_arg(ac, av, &s);
	s.ps = malloc(sizeof(t_philo_struct) * s.arg.philos);
	if (s.ps == NULL)
	{
		printf("Error on memory allocation.\n");
		return (3);
	}
	if (!init_philos(&s) || !create_threads(&s))
		printf("init fail\n"); //
	free(s.ps);
	printf("modif ok\n");
	return (0);
}
