/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:53:13 by mdesfont          #+#    #+#             */
/*   Updated: 2019/12/13 13:18:53 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int			get_next_line(int fd, char **line);
size_t		gnl_strlen(const char *s);
char		*gnl_strjoin(const char *s1, const char *s2);
char		*gnl_strdup(const char *s1);
char		*gnl_substr(char const *s, unsigned int start, size_t len);
char		*gnl_strchr(const char *s, int c);
#endif
