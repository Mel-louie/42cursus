/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 11:11:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** # if defined(__APPLE__)
** # include "key_macos.h"
** # else
** #  include "key_linux.h"
** # endif
*/

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "exit_codes.h"
# include "keys_codes.h"
# include <fcntl.h>
# include <stdio.h>

# define WIN_NAME "So Long!"
# define BUFFER_SIZE 32 

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			p;
	int			e;
	int			mapx;
	int			mapy;
	char		**map;
}				t_mlx;

/*
** CHECKS
*/

int		check_ext(char *file_ext, char *ext);
int		is_ok_char(char c);

/*
** EVENTS
*/

int		key_press(int key, t_mlx *mlx);

/*
** FUNCTIONS THAT EXIT
*/

int		red_cross(t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		close_error(t_mlx *mlx, char *error);

/*
** MAP
*/

void	check_map(char *line, t_mlx *mlx, int last);

/*
** SCREEN
*/

void	window_size(t_mlx *mlx);

#endif
