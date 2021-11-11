/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:57:17 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/11 13:09:23 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
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

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
	{
		display_usages();
		return (1);
	}
	else
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child1(av, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			error();
		if (pid2 == 0)
			child2(av, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
	}
	return (0);
}
