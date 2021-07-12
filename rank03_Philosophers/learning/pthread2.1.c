/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread2.1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:17 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/12 13:51:41 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.youtube.com/watch?v=It0OFCbbTJE&list=
** PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=2
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*myturn(void *arg)
{
	int	i;
	int	*iptr;

	i = 0;
	iptr = (int *)malloc(sizeof(int));
	*iptr = 2;
	while (i < 10)
	{
		sleep(1);
		printf("My turn! %i %i\n", i, *iptr);
		(*iptr)++;
		i++;
	}
	return (iptr);
	(void)arg;
}

void	yourturn(void)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		sleep(2);
		printf("Your turn! %i\n", i);
		i++;
	}
}

int	main(void)
{
	pthread_t	newthread;
	int			*result;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	// wait until a specific thread (here newtrhead) finishes running
	// 2nd arg is to get what the thread returns
	pthread_join(newthread, (void *)&result);
	printf("thread's done: *result = %i\n", *result);
	return (0);
}
