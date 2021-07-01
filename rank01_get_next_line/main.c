#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"


int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;

	line = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			printf("-----------\nEnd of stdin\n");
		}
		close(fd);
	}
	system("leaks GNL");
	return (0);
}
/*
//MULTIPLE FD
int	main(int argc, char const *argv[]) {
int		fd;
 	int		fd2;
	char	*line;
	int		ret; // printing la valeur de retour de gnl

	if (argc > 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			fd = open(argv[1], O_RDONLY);
			fd2 = open(argv[2], O_RDONLY);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("ret:%d line1>%s\n", ret, line);
			free(line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("ret:%d line1>%s\n", ret, line);
			free(line);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("ret:%d line2>%s\n", ret, line);
			free(line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("ret:%d line2>%s\n", ret, line);
			free(line);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("ret:%d line3>%s\n", ret, line);
			free(line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("ret:%d line3>%s\n", ret, line);
			free(line);
			close(fd);
			close(fd2);
		}
	}
	system("leaks GNL");
	return (0);
}*/


