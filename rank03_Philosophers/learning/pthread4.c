/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:17 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/13 19:32:53 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.youtube.com/watch?v=d9s_d28yJq0&list
** =PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*routine(void)
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending threads\n");
}

int	main(int ac, char **av)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, routine, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	return (0);
	(void)av;
	(void)ac;
}
