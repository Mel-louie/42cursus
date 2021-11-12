#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return(i);
}

void	error(char *str, char *arg)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	if (arg)
		write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, "\n", 1);
	kill(0, SIGINT);
}

int	built_cd(int i, char **cmd)
{
	int i_path = i + 1;

	if (!cmd[i_path] || !strncmp(cmd[i_path], "-", 1))
		error("error: cd: bad arguments", NULL);
	if (chdir(cmd[i_path]) != 0)
		error("error: cd: cannot change directory to ", cmd[i_path]);
	return (0);
}

void	child(char **arg, int last, int *fd, int fd_in, char **envp)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		error("error: fatal", NULL);
	if (last == 0)
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error("error: fatal", NULL);
	close(fd_in);
	close(fd[0]);
	close(fd[1]);
	if (execve(arg[0], arg, envp) == -1)
		error("error: cannot execute ", arg[0]);
}

int	ft_exe(char **arg, char **envp, int fd_in)
{
	pid_t pid;
	int fd[2];
	int i;
	int last;

	i = 0;
	last = 0;
	while (arg[i] && strcmp(arg[i], "|"))
		++i;
	if (!arg[i])
		last = 1;
	arg[i] = 0;
	if (pipe(fd) == -1 || (pid = fork()) == -1)
	    error("error: fatal", NULL);
	else if (pid == 0)
       child(arg, last, fd, fd_in, envp);
	else
	{
		if (dup2(fd[0], fd_in) == -1)
   		    error("error: fatal", NULL);
		close(fd[0]);
		close(fd[1]);
	}
	if (last == 0)
		return (i + 1);
	return (i);
}

int	execute(char **arg, char **envp)
{
	int i;
	int status;
	int count;
	int fd_in;

    if (!strcmp(arg[0], "cd"))
			return (built_cd(0, arg));
	if ((fd_in = dup(STDIN_FILENO)) == -1)
	    error("error: fatal", NULL);
	i = 0;
	while (arg[i])
	{
		i += ft_exe(arg + i, envp, fd_in);
		++count;
	}
	close(fd_in);

    /*
    ** wait for all processes to terminated 
    */
	while (count > 0)
	{
		waitpid(-1, &status, 0);
		--count;
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	i = 1;
	int start = 1;

	if (ac < 2)
		return (0);
	while (av[i])
	{
		if (strcmp(av[i], ";") == 0)
		{
			av[i] = 0;
			execute(av + start, envp);
			++i;
			while (av[i] && av[i + 1] && strcmp(av[i], ";") == 0)
				++i;
			start = i;
		}
		else
			++i;
	}
	if (av[start])
		execute(av + start, envp);
	return (0);
}
