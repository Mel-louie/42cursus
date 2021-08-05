/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:54:38 by mdesfont          #+#    #+#             */
/*   Updated: 2021/08/05 15:58:22 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_routine(void *v)
{
	t_philo_struct	*ps;
	long			st;
//	long			t;
	ps = (t_philo_struct *) v;
	while (1)
	{
	/* 1st: philosopher thinks(wait to die) for n seconds */
		st = ps->parg->die;
		printf("%3ld Philosopher %d thinking for %ld seconds\n",
			 time(0) - ps->t0, ps->philos_nb, st);
		fflush(stdout);
		sleep(st);

// 	/* Now, the philosopher wakes up and wants to eat.  He calls pickup
//        to pick up the chopsticks */

// 		printf("%3d Philosopher %d no longer thinking -- calling pickup()\n", 
// 			time(0)-ps->t0, ps->id);
// 		fflush(stdout);
// 		t = time(0);
// 		pickup(ps);
// 		pthread_mutex_lock(ps->blockmon);
// 		ps->blocktime[ps->id] += (time(0) - t);
// 		pthread_mutex_unlock(ps->blockmon);

// 	/* When pickup returns, the philosopher can eat for a random number of
//        seconds */

// 		st = (random()%ps->ms) + 1;
// 		printf("%3d Philosopher %d eating for %d seconds\n", 
// 			time(0)-ps->t0, ps->id, st);
// 		fflush(stdout);
// 		sleep(st);

//     /* Finally, the philosopher is done eating, and calls putdown to
//        put down the chopsticks */

// 		printf("%3d Philosopher %d no longer eating -- calling putdown()\n", 
// 			time(0)-ps->t0, ps->id);
// 		fflush(stdout);
// 		putdown(ps);
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
