/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:54:38 by mdesfont          #+#    #+#             */
/*   Updated: 2021/08/06 16:06:44 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pickup(t_philo_struct *ps)
{
	t_forks	*pp;
	int		phil_count;
	pp = (t_forks *)ps->v;
	phil_count = pp->philos_count;
	pthread_mutex_lock(pp->locks[ps->philos_nb]);					/* lock up left stick */
	printf("\n\tforks left picked by %d\n", ps->philos_nb);
	sleep(3);
	pthread_mutex_lock(pp->locks[(ps->philos_nb+1)%phil_count]);	/* lock up right stick */
	printf("\tforks right picked by %d\n\n", ps->philos_nb);
}

void	putdown(t_philo_struct *ps)
{
	t_forks	*pp;
	int		phil_count;

	pp = (t_forks *)ps->v;
	phil_count = pp->philos_count;
	pthread_mutex_unlock(pp->locks[ps->philos_nb]);					/* unlock up left stick */
	printf("\n\tforks left picked by %d\n", ps->philos_nb);
	pthread_mutex_unlock(pp->locks[(ps->philos_nb + 1) % phil_count]);	/* unlock up right stick */
	printf("\tforks right picked by %d\n\n", ps->philos_nb);
}

void	*start_routine(void *v)
{
	t_philo_struct	*ps;
	long			st;
	long			t;

	ps = (t_philo_struct *) v;
	while (1)
	{
	/* 1st: philosopher sleep for n seconds */
		st = ps->parg->sleep;
		printf("%3ld Philosopher %d thinking for %ld seconds\n",
			 time(0) - ps->t0, ps->philos_nb, st);
		fflush(stdout);
		sleep(st);
// 	/* Now, the philosopher wakes up and wants to eat.  He calls pickup
//        to pick up the chopsticks */
		printf("%3ld Philosopher %d no longer thinking -- calling pickup()\n",
			time(0) - ps->t0, ps->philos_nb);
		fflush(stdout);
		t = time(0);
		pickup(ps);
		pthread_mutex_lock(ps->blockmoni);
		ps->blocknum[ps->philos_nb] += (time(0) - t);
		pthread_mutex_unlock(ps->blockmoni);
	/* When pickup returns, the philosopher can eat */
		st = ps->parg->eat;
		printf("%3ld Philosopher %d eating for %ld seconds\n",
			time(0) - ps->t0, ps->philos_nb, st);
		fflush(stdout);
		sleep(st);
//     /* Finally, the philosopher is done eating, and calls putdown to
//        put down the chopsticks */
		printf("%3ld Philosopher %d no longer eating -- calling putdown()\n",
			time(0) - ps->t0, ps->philos_nb);
		fflush(stdout);
		putdown(ps);
	}
	return (v);
}

int	create_threads(t_structs *s)
{
	int	i;

	i = 0;
	while (i < s->arg.philos)
	{
		s->ps[i].parg = &s->arg;
		pthread_create(&s->ps[i].thread_id, NULL, start_routine, &s->ps[i]);
		i++;
	}
	return (1);
}
