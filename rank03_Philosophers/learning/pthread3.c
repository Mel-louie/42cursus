/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:17 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/13 15:45:56 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.youtube.com/watch?v=9axu8CUvOKY&list=
** PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=3
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BIG 1000000000UL
uint32_t			counter = 0;
pthread_mutex_t		lock = PTHREAD_MUTEX_INITIALIZER;

void	*count_to_big(void *arg)
{
	uint32_t	i;

	i = 0;
	while (i < BIG)
	{
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unclock(&lock);
		i++;
	}
	return (arg);
}

int	main(void)
{
	pthread_t	t;

	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Done. Counter = %d\n", counter);
	return (0);
}
