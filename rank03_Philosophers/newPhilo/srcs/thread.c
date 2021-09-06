/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:18:19 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/06 15:10:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	philo_eat(t_philo *philo, int *eat)
{
	pthread_mutex_lock(&philo->last_ate_mutex);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->last_ate_mutex);
	philo_write(philo, "\033[32mis eating\033[0m");
	*eat += 1;
}

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

int	set_thread(t_data *data, t_philo *philo, pthread_t *thread)
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
