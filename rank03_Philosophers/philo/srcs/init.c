/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:47:52 by louielouie        #+#    #+#             */
/*   Updated: 2021/08/05 15:48:19 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_structs *s)
{
	int				i;
	int				*blocknum;
	pthread_mutex_t	*blockmoni;
	long			t0;
	//	void			*v;

	srandom(time(0));
	i = 0;
	blockmoni = NULL;
	t0 = time(0);
	//v = init_state(s.arg.philos);
	blocknum = malloc(sizeof(int) * s->arg.philos);
	blockmoni = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(blockmoni, NULL);
	while (i < s->arg.philos)
	{
		s->ps[i].philos_nb = i + 1;
	//	s.ps[i].v = v;
		s->ps[i].t_to_die = s->arg.die;
		s->ps[i].t_to_eat = s->arg.eat;
		s->ps[i].t_to_sleep = s->arg.sleep;
		s->ps[i].must_eat_nb = s->arg.must_eat;
		s->ps[i].blocknum = blocknum;
		s->ps[i].blockmoni = blockmoni;
		s->ps[i].t0 = t0;
		i++;
	}
	return (1);
}

void	usage(int code)
{
	if (code == 1)
	{
		printf("-- First agument is the number of Philosophers\n");
		printf(" \t must be between 1 and 200.\n");
	}
	if (code == 2)
	{
		printf("-- Launch ./philo:\n\n");
		printf("\t./philo [number_of_pholisophers] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat](<- optional)\n\n");
		printf("\t[time_to_die] should be > 0\n");
		printf("\t[time_to_eat] should be > 0\n");
		printf("\tand [time_to_sleep] should be > 0\n");
	}
}

int	get_arg(int ac, char **av, t_structs *s)
{
	s->arg.philos = ft_atoi(av[1]);
	if (s->arg.philos < 1 || s->arg.philos > 200)
	{
		usage(1);
		return (2);
	}
	s->arg.die = ft_atoi(av[2]);
	s->arg.eat = ft_atoi(av[3]);
	s->arg.sleep = ft_atoi(av[4]);
	s->arg.must_eat = -1;
	if (ac == 6)
		s->arg.must_eat = ft_atoi(av[5]);
	if (s->arg.die < 1 || s->arg.eat < 1 || s->arg.sleep < 1)
	{
		usage(2);
		return (2);
	}
	return (0);
}
