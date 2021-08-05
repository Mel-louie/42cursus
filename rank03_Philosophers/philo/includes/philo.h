/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:31:27 by mdesfont          #+#    #+#             */
/*   Updated: 2021/08/05 12:26:40 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>

/*
** must_eat_nb: 
** if allphilosophers eat at least [must_eat_nb] the simulation will stop
** if not specified, the simulation will stop only at the death of a philosopher
*/

typedef struct s_settings
{
	int		philos_nb;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		must_eat_nb;
}			t_settings;

int	main(int ac, char **av);
int	handle_errors(int ac, char **av);
int	ft_atoi(const char *str);
int	get_arg(int ac, char **av, t_settings *set);

#endif