/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:54:38 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/03 20:16:40 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** implémente les procédures en faisant en sorte que chaque baguette soit
** un moniteur (mutex),
** et que chaque philosophe tente de ramasser la baguette de sa gauche en
** premier, puis de sa droite,
** puis de manger, puis de poser la droite, puis de poser la gauche.
** 
** Cette méthode est sujette à des blocages, bien que sur ce système,
** vous n'en verrez jamais vraiment
** à cause de la granularité des temps entre les threads. La seule fois
** où cette solution pose un problème
** est si le thread d'un philosophe est préempté entre le ramassage du
** premier et du second mutex. 
** cela n'arrive pas vraiment ici, donc il semble que cela fonctionne très bien.
** 
** mais avec un délai de 3 secondes entre la prise de la baguette 1 et la prise
** de la baguette 2
** vous obtenez un blocage instantané si tous les philosophes essaient de
** ramasser leurs baguettes en même temps.
** 
** donc en faitsant en sorte que les philosophes impairs commencent à gauche en
** premier (if (ps->philos_nb % 2 == 1)),
** et les philosophes pairs à droite en premier, cela ne bloque pas, même si
** vous mettez un délai entre le ramassage
** des baguettes une et deux (sleep(3)).
** 
** problem possible: one thread can get more resources than the others due to
** your synchronization protocol
*/

void	pickup(t_philo_struct *ps)
{
	t_forks	*pp;
	int		phil_count;

	pp = (t_forks *)ps->v;
	phil_count = pp->philos_count;
	if (ps->philos_nb % 2 == 1)
	{
		pthread_mutex_lock(pp->locks[ps->philos_nb]);
		printf("_ms Philosopher %d has taken a fork\n", ps->philos_nb);
		pthread_mutex_lock(pp->locks[(ps->philos_nb + 1) % phil_count]);
		printf("_ms Philosopher %d has taken a fork\n", ps->philos_nb);
	}
	else
	{
		pthread_mutex_lock(pp->locks[(ps->philos_nb + 1) % phil_count]);
		printf("_ms Philosopher %d has taken a fork\n", ps->philos_nb);
		pthread_mutex_lock(pp->locks[ps->philos_nb]);
		printf("_ms Philosopher %d has taken a fork\n", ps->philos_nb);
	}
}

void	putdown(t_philo_struct *ps)
{
	t_forks	*pp;
	int		phil_count;

	pp = (t_forks *)ps->v;
	phil_count = pp->philos_count;
	if (ps->philos_nb % 2 == 1)
	{
		pthread_mutex_unlock(pp->locks[(ps->philos_nb + 1) % phil_count]);
		pthread_mutex_unlock(pp->locks[ps->philos_nb]);
	}
	else
	{
		pthread_mutex_unlock(pp->locks[ps->philos_nb]);
		pthread_mutex_unlock(pp->locks[(ps->philos_nb + 1) % phil_count]);
	}
}

/*
** *****************************************************************************
** 1st: philosopher eats for n seconds
** He calls pickup to pick up the forks
** Finally, the philosopher is done eating, and calls putdown to
** put down the forks
**
** 
** *****************************************************************************
*/

void	*start_routine(void *v)
{
	t_philo_struct	*ps;
	long			st;

	ps = (t_philo_struct *) v;
	while (1)
	{
		st = ps->parg->eat;
		pickup(ps);
		printf("\033[32m _ms Philosopher %d is eating\033[0m\n", ps->philos_nb);
		sleep(st);
		putdown(ps);
		st = ps->parg->sleep;
		printf("\033[33m _ms Philosopher %d is sleeping\033[0m\n", ps->philos_nb);
		sleep(st);
		st = ps->parg->die;
		printf("\033[34m _ms Philosopher %d is thinking\033[0m\n", ps->philos_nb);
		sleep(st);
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
	i = 0;
	while (i < s->arg.philos)
	{
		pthread_join(s->ps[i].thread_id, NULL);
		i++;
	}
	return (1);
}
