/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:41:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/09/02 16:19:36 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <string.h>

int	main(int ac, char **av)
{
	t_structs	s;
	t_utils		u;

	u.error_code = 0;
	if (handle_errors(ac, av) == 1)
		return (1);
	get_arg(ac, av, &s);
	s.ps = malloc(sizeof(t_philo_struct) * s.arg.philos);
	if (s.ps == NULL)
		u.error_code = alloc_error(3);
	if (!init_philos(&s, &u) || !create_threads(&s))
		printf("init fail\n"); //
	free(s.ps);
	return (u.error_code);
}
