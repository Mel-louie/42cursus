/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 18:42:42 by user42           ###   ########.fr       */
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
# define BLOCK 32

/*
** STRUCTS
*/

enum {UP, DOWN, RIGHT, LEFT};

typedef struct s_items
{
	int			exitx;
	int			exity;
}				t_items;

typedef struct s_player
{
	int			posx;
	int			posy;
	int			direction;
	int			colec;
	int			nb_to_colec;
}				t_player;

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			s_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
	char		*name;
}				t_img;

typedef struct s_settings
{
	char		*path_fl;
	char		*path_wa;
	char		*path_co;
	char		*path_pl;
	char		*path_en;
	t_img		t_fl;
	t_img		t_wa;
	t_img		t_co;
	t_img		t_pl;
	t_img		t_en;
}				t_settings;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			p;
	int			e;
	int			c;
	int			mapx;
	int			mapy;
	char		**map;
	t_img		img;
	t_settings	set;
	t_player	pl;
	t_items	pos;
}				t_mlx;

/*
** CHECKS
*/

int		check_ext(char *file_ext, char *ext);
int		is_ok_char(char c);
int		try_open(char *file);
int		check_tiles(void);
void	check_char(t_mlx *mlx);

/*
** EVENTS
*/

int		key_press(int key, t_mlx *mlx);

/*
** FUNCTIONS THAT EXIT
*/

int		red_cross(t_mlx *mlx);
int		close_window(t_mlx *mlx, char *str);
int		close_error(t_mlx *mlx, char *error);

/*
** MAP
*/

void	check_map(char *line, t_mlx *mlx, int last);
void	parse_file(int fd, t_mlx *mlx);
void	fill_map(int fd, char *filename, t_mlx *mlx, int i);
void	draw_map(t_mlx *mlx);

/*
** SCREEN
*/

void	window_size(t_mlx *mlx);

/*
** TILES
*/

void	get_path(t_mlx *mlx);
void	get_img_texture(t_mlx *mlx);

/*
** PLAYER MOVES
*/

void	get_player_pos(t_mlx *mlx);
void	move_player(t_mlx *mlx, int dy, int dx);

#endif
