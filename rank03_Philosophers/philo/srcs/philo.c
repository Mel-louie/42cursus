/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:41:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/08/06 15:30:23 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <string.h>

int	main(int ac, char **av)
{
	t_structs		s;
	char			str[500];
	char			*curr;
	int				total;
	int				i;

	if (handle_errors(ac, av) == 1)
		return (1);
	get_arg(ac, av, &s);
	s.ps = malloc(sizeof(t_philo_struct) * s.arg.philos);
	if (s.ps == NULL)
	{
		printf("Error on memory allocation.\n"); //faire fonction exit
		return (3);
	}
	if (!init_philos(&s) || !create_threads(&s))
		printf("init fail\n"); //
	
	//
	int j = 0;
	int tmp;
	if (s.ps->must_eat_nb != -1)
		tmp = s.ps->must_eat_nb;
	else
		tmp = 1; //suppr to push, doit etre infini
	//printf("%d\n", tmp);
	while(j < tmp)
	{
	//	printf("%d\n", j);
		pthread_mutex_lock(s.ps->blockmoni);
		curr = str;
		total = 0;
		for(i = 0; i < s.ps->philos_nb; i++)
			total += s.ps->blocknum[i];
		sprintf(curr, "%3ld Total blocktime: %5d : ",
			time(0) - s.ps->t0, total);
		curr = str + strlen(str);
		for(i=0; i < s.ps->philos_nb; i++)
		{
			sprintf(curr, "%5d ", s.ps->blocknum[i]);
			curr = str + strlen(str);
		}
		pthread_mutex_unlock(s.ps->blockmoni);
		printf("%s\n", str);
		fflush(stdout);
		sleep(10);
		j++;
	}
	//
	
	free(s.ps);
	return (0);
}
