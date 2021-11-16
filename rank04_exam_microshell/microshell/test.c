#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	error(char *s)
{
	int i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	return (1);
}

int	fatal(char *s, char **ptr)
{
	if (ptr != NULL)
		free(ptr);
	exit(error(s));
}

int	size_cmd_char(char **cmd, char *str)
{
	if (!cmd)
		return (0);
	int i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], str))
			return (i);
	return (i);
}

char	**add_cmd(char **av, int *i)
{
	int size = size_cmd_char(&av[*i], ";");
	if (!size)
		return (NULL);

	char **tmp = NULL;
	if (!(tmp = malloc(sizeof(*tmp) * (size + 1))))
		fatal("fatal",NULL);

	int j = -1;
	while (++j < size)
		tmp[j] = av[j + *i];
	tmp[j] = NULL;
	*i += size;
	return (tmp);
}

int size_cmd(char **cmd)
{
	if (!cmd)
		return (0);
	int i = -1;
	while (cmd[++i]);
	return (i);
}

int	builtin_cd(char (**cmd))
{
	if (size_cmd(cmd) < 2)
		return (error("error voulue\n"));
	if (chdir(cmd[1]) < 0)
	{
		error("voulue 2\n");
	}
	return (0);
}

char	**find_pipes(char **cmd)
{
	if (!cmd)
		return (NULL);
	int i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return (&cmd[i + 1]);
	return (NULL);
}

int exe_cmd(char **cmd, char **env, char **ptr)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		fatal("free", ptr);
	if (!pid) // son
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			error("error: cannot execute ");
			error(cmd[0]);
			free(ptr);
			exit(error("\n"));
		}
	}
	waitpid(0, NULL, 0);
	return (0);
}

int	exe_child(char **cmd, char **env, int fd_in, int fd_pipe[2], char **tmp)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		fatal("null",cmd);
	if (find_pipes(tmp) && dup2(fd_pipe[1], STDOUT_FILENO) < 0)
		fatal("null",cmd);

	close(fd_in);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	
	tmp[size_cmd_char(tmp, "|")] = NULL;
	exe_cmd(tmp, env, cmd);

	free(cmd);
	exit(0);
}

int	execute(char **cmd, char **env)
{
	if (!find_pipes(cmd))
		return (exe_cmd(cmd, env, cmd));

	int fd_in;
	int fd_pipe[2];
	int nbwait = 0;
	char **tmp = cmd;
	pid_t pid;

	if ((fd_in = dup(STDIN_FILENO)) < 0)
		return (fatal("fatal", cmd));

	while (tmp)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			fatal("err", cmd);

		if (!pid)
			exe_child(cmd, env, fd_in, fd_pipe, tmp);

		else 
		{
			if ((dup2(fd_pipe[0], fd_in) < 0))
				fatal("dup2\n", cmd);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			++nbwait;
			tmp = find_pipes(tmp);
		}
	}

	close(fd_in);
	while (nbwait-- >= 0)
		waitpid(0, NULL, 0);

	return (0);
}

int	main(int ac, char **av, char **env)
{
	int i = 0;
	char **cmd = NULL;

	while (++i < ac)
	{
		cmd = add_cmd(av, &i);

		if (cmd && !strcmp(cmd[0], "cd"))
			builtin_cd(cmd);

		else if (cmd)
			execute(cmd, env);


		// int x = 0;
		// while (cmd[x])
		// {
		// 	printf("cmd: %s\n", cmd[x]);
		// 	x++;
		// }

		if (cmd != NULL)
			free(cmd);
		cmd = NULL;

	}

	//system("leaks microshell");
(void)env;
	return (0);
}