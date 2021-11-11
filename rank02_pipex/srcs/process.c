/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:46:58 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/11 13:31:38 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child1(char **av, char **envp, int *fd)
{
	int	infile;

	close(fd[0]);
	infile = open(av[1],O_RDONLY, 0644);
	if (infile == -1)
	{
		perror(av[1]);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(infile);
	execute(av[2], envp);
}

void	child2(char **av, char **envp, int *fd)
{
	int		outfile;

	close(fd[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror(av[4]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(outfile);
	execute(av[3], envp);
}
