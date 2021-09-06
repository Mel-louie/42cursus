/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:18:19 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/06 16:51:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
** *****************************************************************************
on commence par lock la fourchette de gauche du philo, pour pas qu'un autre la
prenne d'ici a ce que les verif aient ete faites, ou que le philo ait mange
s'il est mot > unlock, sortie de la fonction
lock la fourcette a sa droite
si mort > unlock sortie
** *****************************************************************************
*/

int	get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork_mutex);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->lfork_mutex);
		return (1);
	}
	philo_write(philo, "has taken a fork");
	pthread_mutex_lock(philo->rfork_mutex);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->lfork_mutex);
		pthread_mutex_unlock(philo->rfork_mutex);
		return (1);
	}
	philo_write(philo, "has taken a fork");
	return (0);
}

/*
** *****************************************************************************
mutex pour last_ate qui va permettre de verouiller l'info temps pour ce philo_id
pour avoir le get_time

puis l'affichage que le philo mange
** *****************************************************************************
*/

void	philo_eat(t_philo *philo, int *eat)
{
	pthread_mutex_lock(&philo->last_ate_mutex);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->last_ate_mutex);
	philo_write(philo, "\033[32mis eating\033[0m");
	*eat += 1;
}

/*
** *****************************************************************************
 if (philo->id % 2 == 0)
		usleep(200);
permet de faire attendre les philos dont l'id est positif, et donc d'avoir des
demarage en decale des threads des philos paires et impaires
cela evite que 2 voisins de table prennent la meme fourchette avant qu'elle ne
soit lock
** *****************************************************************************
*/

void	*start_thread(void *arg)
{
	t_philo	*philo;
	int		eat;

	philo = arg;
	eat = 0;
	if (philo->id % 2 == 0)
		usleep(200);
	while (eat != philo->data->eat_times && is_dead(philo) == 0)
	{
		if (get_fork(philo))
			break ;
		philo_eat(philo, &eat);
		philo_write(philo, "is sleeping");
		time_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->lfork_mutex);
		pthread_mutex_unlock(philo->rfork_mutex);
		if (is_dead(philo))
			break ;
		philo_write(philo, "is thinking");
		time_sleep(philo->data->time_to_sleep);
	}
	set_state(philo);
	return (NULL);
}

int	set_threads(t_data *data, t_philo *philo, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (init_philo(data, &philo[i], i))
			return (1);
		if (pthread_create(&thread[i], NULL, start_thread, &philo[i]))
			return (1);
		++i;
	}
	died(philo, data);
	i = 0;
	while (i < data->num)
	{
		pthread_join(thread[i], NULL);
		++i;
	}
	return (0);
}
