/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:31:27 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/01 18:41:36 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

/*
** *****************************************************************************
** 
** *****************************************************************************
*/

typedef struct s_forks
{
	pthread_mutex_t	**locks;
	int				philos_count;
}					t_forks;

typedef struct s_arg_struct
{
	int				philos;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
}			t_arg_struct;

/*
** *****************************************************************************
** must_eat_nb:
** if allphilosophers eat at least [must_eat_nb] the simulation will stop
** if not specified, the simulation will stop only at the death of a philosopher
**
** blocknum:
** total time that a philosopher is blocked
**
** blockmoni:
** monitor for blocknum
** *****************************************************************************
*/

typedef struct s_philo_struct
{
	int				philos_nb;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				must_eat_nb;
	pthread_t		thread_id;
	void			*v;
	int				*blocknum;
	pthread_mutex_t	*blockmoni;
	t_arg_struct	*parg;
	long			t0;
}			t_philo_struct;

typedef struct s_structs
{
	t_philo_struct	*ps;
	t_arg_struct	arg;
}			t_structs;

int	main(int ac, char **av);
int	handle_errors(int ac, char **av);
int	ft_atoi(const char *str);
int	get_arg(int ac, char **av, t_structs *s);
int	init_philos(t_structs *s);
int create_threads(t_structs *s);

#endif