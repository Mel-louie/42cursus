/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:49:57 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/03 18:57:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*
** STRUCTS
*/

typedef struct s_stack
{
	int			*stack;
	int			size;
	int			min;
	int			min_n;
	int			pos_min;
	int			pos_min_n;
	int			max;
	int			pos_max;
	int			flag;
}				t_stack;

typedef struct s_utils
{
	int			len;
	int			max;
	int			min;
	int			median;
	int			arr_min;
	int			arr_med;
	int			arr_end;
	int			*arr;
}				t_utils;

/*
** PUSH_SWAP FUNCTIONS
*/

int			errors(int argc, char **argv, int i);
int			get_position(int *stack, int len, int nb);
int			get_min(int *stack, int len);
int			get_pivot(t_stack *a, int size);
int			is_duplicate(int argc, char **argv, int i, int j);
int			is_sorted(t_stack *a, int size);
int			is_sorted_rev(t_stack *a);
void		*free_stack(int *stack);
char		**parse(int argc, char **argv, t_utils *u);
void		quicksort_five_hundred(t_stack *a, t_stack *b,
				t_utils *u, int size);
void		sort(t_stack *a, t_stack *b, t_utils *u);
void		five_hundred_stack_a(t_stack *a, t_stack *b, int i);
void		sort_hundred(t_stack *a, t_stack *b, t_utils *u);
void		sort_five_num(t_stack *a, t_stack *b);
void		sort_three_num(t_stack *a);
void		is_biggest(t_stack *a);
void		is_lowest(t_stack *a);
int			set_median(t_utils *u, int size, int *stack);
int			find_best_med(t_utils *u, t_stack *a, int size);

/*
** INSTRUCTIONS
*/

void		instructions(char *inst, t_stack *a, t_stack *b);
void		ft_swap(t_stack *a, t_stack *b, int swap);
int			ft_rotate(t_stack *a, t_stack *b, int ro);
int			ft_revrotate(t_stack *a, t_stack *b, int rro);
int			ft_push(t_stack *push, t_stack *pop);

/*
** UTILS FUNCTIONS
*/

int			ft_atoi(const char *str);
long long	ft_great_atoi(const char *str);
int			ft_isdigit(char n);
int			ft_isnumber(char *n);
void		*free_str(char *s);
char		**free_tab(char **tab);
void		ft_putstr_fd(char *str, int fd);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(const char *str, char c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		**ft_tabdup(char **tab);
void		ft_write_inst(char *str);

#endif