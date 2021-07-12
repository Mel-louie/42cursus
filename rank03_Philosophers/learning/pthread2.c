/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:17 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/12 13:28:46 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.youtube.com/watch?v=It0OFCbbTJE&list=
** PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=2
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*myturn(void *arg)
{
	int	i;
	int	*iptr;

	i = 0;
	iptr = (int *)arg;
	while (i < 10)
	{
		sleep(1);
		printf("My turn! %i %i\n", i, *iptr);
		(*iptr)++;
		i++;
	}
	return (arg);
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
	int			v;

	v = 5;
	pthread_create(&newthread, NULL, myturn, &v);
	yourturn();
	pthread_join(newthread, NULL);
	printf("thread's done: v = %i\n", v);
	return (0);
}
