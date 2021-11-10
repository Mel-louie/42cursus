/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:00:01 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/10 17:18:12 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	display_usages(void)
{
	{
		write(1, "\n*************************************\n", 39);
		write(1, "Usage:\n", 7);
		write(1, "Pipex should be use like this:", 30);
		write(1, "\n\t./pipex file1 cmd1 cmd2 file2\n", 32);
		write(1, "*************************************\n\n", 39);
	}	
}
