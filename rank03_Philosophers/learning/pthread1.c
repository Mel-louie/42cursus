/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:17 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/12 13:16:15 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.youtube.com/watch?v=uA8X5zNOGw8&list=
** PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=1
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
** void	myturn(void)
** {
** 	while (1)
** 	{
** 		sleep(1);
** 		printf("My turn!\n");
** 	}
** }
*/

void	*myturn(void *arg)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		sleep(1);
		printf("My turn! %i\n", i);
		i++;
	}
	return (arg); //arg == NULL, passé depuis pthread_create
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

	pthread_create(&newthread, NULL, myturn, NULL);
	//myturn();
	yourturn();
	pthread_join(newthread, NULL); // wait until a specific thread (here newtrhead) finishes running
	return (0);
}
