/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:58:15 by mdesfont          #+#    #+#             */
/*   Updated: 2019/12/30 15:24:25 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char		*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (0);
}

static int	gnl_newline(char **save, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = gnl_substr(*save, 0, i);
		tmp = gnl_strdup(&(*save)[i + 1]);
		free(*save);
		*save = tmp;
	}
	else if ((*save)[i] == '\0')
	{
		*line = gnl_strdup(*save);
		free(*save);
		*save = NULL;
		return (0);
	}
	return (1);
}

static int	gnl_compare(int br, int fd, char **sv, char **line)
{
	if (br < 0)
		return (-1);
	else if (br == 0 && sv[fd] == NULL)
	{
		*line = gnl_strdup("");
		free(*sv);
		*sv = NULL;
		return (0);
	}
	else
		return (gnl_newline(&sv[fd], line));
}

int			get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*save[OPEN_MAX];
	char			*tmp;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || (!(buffer = malloc
		(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[bytes_read] = '\0';
		if (save[fd] == NULL)
			save[fd] = gnl_strdup(buffer);
		else
		{
			tmp = gnl_strjoin(save[fd], buffer);
			free(save[fd]);
			save[fd] = tmp;
		}
		if (gnl_strchr(save[fd], '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (gnl_compare(bytes_read, fd, save, line));
}
