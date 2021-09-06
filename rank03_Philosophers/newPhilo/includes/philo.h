/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:18:02 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/06 15:33:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>

# define DEAD 0
# define ALIVE 1
# define OK 2

/*
** *****************************************************************************
** struct de toutes les datas dont il y a besoin par philos
** *****************************************************************************
*/

typedef struct s_data
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				state;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	phi_write;
	unsigned long	starttime;
}					t_data;

typedef struct s_philo
{
	int				id;
	unsigned long	last_ate;
	pthread_mutex_t	*lfork_mutex;
	pthread_mutex_t	*rfork_mutex;
	pthread_mutex_t	last_ate_mutex;
	t_data			*data;
}					t_philo;

void			ft_putchar_fd(char c, int fd);
void			ft_put_ul_fd(unsigned long n, int fd);
int				ft_putstr_fd(const char *s, int fd, int ret);
int				ft_atoi(const char *str);
void			philo_write(t_philo *philo, char *s);
int				init_philo(t_data *data, t_philo *philo, int i);
int				parsing(t_data *data, int ac, char **av);
unsigned long	get_time(void);
int				is_dead(t_philo *philo);
void			time_sleep(unsigned long time_to_sleep);
int				died(t_philo *philo, t_data *data);
void			set_state(t_philo *philo);
int				set_threads(t_data *data, t_philo *philo, pthread_t *thread);

#endif
