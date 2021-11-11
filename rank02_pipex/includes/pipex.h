/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:00:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/11 13:08:44 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>

void	error(void);

/*
 * PROCESS
 */

void		child1(char **av, char **envp, int *fd);
void		child2(char **av, char **envp, int *fd);

/*
 * EXECUTE
 */

void		execute(char *av, char **envp);
char		*find_path(char *cmd, char **envp);

/*
 * SPLIT
 */

char		*ft_strndup(const char *s, size_t n);
char		**ft_split(const char *str, char c);

/*
 * MINI LIBFT
 */

char		*ft_strcpy(char *dest, const char *src);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strjoinfree(char *dest, char *src);

#endif
