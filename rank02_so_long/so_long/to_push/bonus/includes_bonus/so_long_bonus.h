/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 22:03:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libs/libft/includes/libft.h"
# include "../../libs/mlx/mlx.h"
# include "exit_codes_bonus.h"
# include "keys_codes_bonus.h"
# include "structs_bonus.h"
# include <fcntl.h>
# include <stdio.h>

# define WIN_NAME "So Long!"
# define BUFFER_SIZE 32
# define MULTIPLE 64

int				run_game(t_mlx *mlx);
void			free_game(t_mlx *mlx);

/*
** CHECKS
*/

int				check_ext(char *file_ext, char *ext);
int				is_ok_char(char c);
int				try_open(char *file);
int				check_tiles(t_mlx *mlx);
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

void			check_map(char *line, t_mlx *mlx, int last, int i);
void			parse_file(int fd, t_mlx *mlx, int i);
void			fill_map(int fd, char *filename, t_mlx *mlx, int i);
void			draw_map(t_mlx *mlx);

/*
** SCREEN
*/

void			window_size(t_mlx *mlx);
void			display_moves(t_mlx *mlx);

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
void			update_pl_pos(t_mlx *mlx, int dy, int dx);

/*
** COLLECTIBLES
*/

void			push_to_lst(t_mlx *mlx, int y, int x);
t_elem_colec	*get_colectibles(t_mlx *mlx, int y, int x);
void			collected(t_mlx *mlx);
int				colect_all(t_mlx *mlx);

/*
** ENEMIES
*/

void			push_to_lst_enemies(t_mlx *mlx, int y, int x);
t_elem_enemy	*get_enemies(t_mlx *mlx, int y, int x);
void			defeat(t_mlx *mlx);

/*
** EXITS
*/

t_elem_exit		*get_exits(t_mlx *mlx, int y, int x);
void			push_to_lst_exits(t_mlx *mlx, int y, int x);
void			is_an_exit(t_mlx *mlx, int dy, int dx);

#endif
