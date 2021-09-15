#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_shell
{
	char	**env;
	int		start;
	int		end;
}				t_shell;

int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return(i);
}

int	size_cmd(char **cmd, int i, t_shell *sh)
{
	while (cmd[i][sh->end] && strcmp(cmd[i], ";"))
		sh->end++;
	return (sh->end);
}

char	*add_cmd(char **cmd, int i, t_shell *sh)
{
	char	*tmp = malloc(sizeof(char) * ft_strlen(cmd[i]));
	sh->end = 0;
	sh->start = 0;

	sh->end = size_cmd(cmd, i, sh);
	if (!sh->end)
		return (NULL);

	while (sh->start < sh->end)
	{
		tmp[sh->start] = cmd[i][sh->start];
		sh->start++;
	}
	return (tmp);
}

int	built_cd(char *cd, int i, char **cmd)
{
	int i_path = i + 1;
	// printf("cmd i %s +1 %s", cmd[i], cmd[i + 1]);
	if (!cmd[i_path] || !strncmp(cmd[i_path], "-", 1))
		write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	if (chdir(cmd[i_path]) != 0)
	{
		write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
		write(2, cmd[i_path], ft_strlen(cmd[i_path]));
		write(2, "\n", 1);
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	t_shell	sh;
	int	i = 1;
	char	*cmd = NULL;

	sh.env = env;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if ((cmd = add_cmd(av, i, &sh)) != NULL)
		{
			if (!strcmp(cmd, "cd"))
				built_cd(cmd, i, av);
			//  printf("cmd %s\n", cmd);
		}
		free(cmd);
		cmd = NULL;
		i++;
	}
	free(cmd);
	cmd = NULL;
	return (0);
}
