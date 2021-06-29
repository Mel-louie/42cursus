#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/*
** ALLOC
*/

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

/*
** ATOIs ITOAs
*/

long long	ft_great_atoi(const char *str);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

/*
** FREEs
*/

void		*free_int_tab(int *stack);
void		*free_str(char *s);
char		**free_tab(char **tab);

/*
** IS
*/

int			ft_isdigit(char n);

/*
** PUTS
*/

void		ft_putstr_fd(char *str, int fd);

/*
** STRs
*/

char		*ft_strndup(const char *s, size_t n);
char		*ft_strdup(const char *s1);
char		**ft_split(const char *str, char c);
int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoinfree(char *dest, char *src);
int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);

/*
** TABs
*/

size_t		ft_tablen(char **tab);
char		**ft_tabdup(char **tab);

/*
** SORTs
*/

void		simple_swap(int *a, int *b);

/*
** GNL
*/

int			get_next_line(int fd, char **line);

#endif
