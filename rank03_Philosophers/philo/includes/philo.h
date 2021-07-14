/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:31:27 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/14 14:03:29 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>

typedef struct s_settings
{
	int		philos_nb;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		opt_must_eat_nb;
}			t_settings;

int	main(int ac, char **av);
int	handle_errors(int ac, char **av);
int	ft_atoi(const char *str);
int	get_arg(int ac, char **av, t_settings *set);

#endif