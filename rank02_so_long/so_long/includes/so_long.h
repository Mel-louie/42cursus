/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/28 23:46:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "exit_codes.h"
# include "keys_codes.h"
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>

# define WIN_NAME "So Long!"
# define BUFFER_SIZE 32
# define MULTIPLE 32

int				run_game(t_mlx *mlx);

/*
** CHECKS
*/

int				check_ext(char *file_ext, char *ext);
int				is_ok_char(char c);
int				try_open(char *file);
int				check_tiles(void);
void			check_char(t_mlx *mlx);

/*
** EVENTS
*/

int				key_press(int key, t_mlx *mlx);
int				red_cross(t_mlx *mlx);

/*
** FUNCTIONS THAT EXIT
*/

int				close_window(t_mlx *mlx, char *str);
int				close_error(t_mlx *mlx, char *error);
void			victory(t_mlx *mlx);

/*
** MAP
*/

void			check_map(char *line, t_mlx *mlx, int last);
void			parse_file(int fd, t_mlx *mlx);
void			fill_map(int fd, char *filename, t_mlx *mlx, int i);
void			draw_map(t_mlx *mlx);

/*
** SCREEN
*/

void			window_size(t_mlx *mlx);

/*
** TILES
*/

void			get_path(t_mlx *mlx);
void			get_img_texture(t_mlx *mlx);

/*
** PLAYER MOVES
*/

void			get_player_pos(t_mlx *mlx);
void			move_player(t_mlx *mlx, int dy, int dx);

/*
** COLLECTIBLES
*/

void			push_to_lst(t_mlx *mlx, int y, int x);
t_elem_colec	*get_colectibles(t_mlx *mlx, int y, int x);
void			collected(t_mlx *mlx);
int				colect_all(t_mlx *mlx);

#endif
