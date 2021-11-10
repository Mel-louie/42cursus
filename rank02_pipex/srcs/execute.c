/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:14:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/10 18:45:42 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoinfree(paths[i], "/");
		path = ft_strjoinfree(part_path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}


void	execute(char *av, char **envp)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}
