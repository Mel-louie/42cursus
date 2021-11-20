#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


char **find_pipe(char **cmd)
{
	if (!cmd)
		return (NULL);
	int i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return (&cmd[i + 1]);
	return (NULL);
}

int	error(char *str)
{
	int i = -1;
	while (str[++i])
		write(STDERR_FILENO, &str[i], 1);
	return (1);
}

int fatal(char **ptr)
{
	free(ptr);
	exit(error("error: fatal\n"));
}

int exe_cmd(char **cmd, char **env)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		fatal(cmd);

	if (!pid)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			error("error exe: ");
			error(cmd[0]);
		//	free(cmd[0]);
			exit(error("\n"));
		}
	}
	waitpid(0, NULL, 0);
	return (0);
}

int	size_char(char **cmd, char *str)
{
	if (!cmd)
		return (0);
	int i = -1;
	while (cmd[++i])
		if (!strcmp(cmd[i], str))
			return (i);
	return (i);
}

int	exe_child(char **cmd, char **tmp, char **env, int *fd_pipe, int fd_in)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		fatal(cmd);
	if (find_pipe(tmp) && dup2(fd_pipe[1], STDOUT_FILENO) < 0)
		fatal(cmd);

	close(fd_in);
	close(fd_pipe[0]);
	close(fd_pipe[1]);

	tmp[size_char(tmp, "|")] = NULL;
	exe_cmd(tmp, env);

	free(cmd);
	exit(0);
}

int execute(char **cmd, char **env)
{
	if (find_pipe(cmd) == NULL)
		return (exe_cmd(cmd, env));

	int fd_in;
	int fd_pipe[2];
	int nb_wait = 0;
	char **tmp = cmd;
	pid_t pid;

	if ((fd_in = dup(STDIN_FILENO)) < 0)
		return (fatal(cmd));

	while (tmp)
	{
		if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
			fatal(cmd);
		if (!pid)
			exe_child(cmd, tmp, env, fd_pipe, fd_in);
		else
		{
			if (dup2(fd_pipe[0], fd_in) < 0)
				fatal(cmd);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			++nb_wait;
			tmp = find_pipe(tmp);
		}
	}

	close(fd_in);

	while (--nb_wait >= 0)
		waitpid(0, NULL, 0);

	return (0);
}

char **add_cmd(char **cmd, int *i)
{
	int size = size_char(&cmd[*i], ";");
	if (!size)
		return (NULL);
	
	char **tmp = NULL;
	if (!(tmp = malloc(sizeof(*tmp) * (size + 1))))
		fatal(NULL);

	int j = -1;
	while (++j < size)
		tmp[j] = cmd[j + *i];
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

int	builtin_cd(char **cmd)
{
	if (size_cmd(cmd) != 2)
		return (error("cd arg wrooooong\n"));
	if (chdir(cmd[1]) < 0)
	{
		error("error chdir ");
		error(cmd[1]);
		error("\n");
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	int i = 0;

	while (++i < ac)
	{
		cmd = add_cmd(av, &i);

		if (cmd && !strcmp(cmd[0], "cd"))
			builtin_cd(cmd);

		else if (cmd)
			execute(cmd, env);

		if (cmd)
			free(cmd);
		cmd = NULL;
	}

	return (0);
}

