/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:02:59 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/03 08:58:44 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# if defined(__APPLE__)
#  include "key_macos.h"
# else
#  include "key_linux.h"
# endif

# include "../libs/libft/src/libft.h"
# include "../libs/mlx/mlx.h"
# include "exit_codes.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>

# define WIN_NAME "cub3D"

void			init_screen(t_mlx *mlx, int screen_x, int screen_y);
int				ft_isspace(char c);
int				run_game(t_mlx *mlx);
void			save_bmp(t_mlx *mlx);
int				try_open(char *file);
void			init_game(t_mlx *mlx);
void			initial_settings(t_settings *set);
int				red_cross(t_mlx *mlx);
void			init_img(t_img *img);
void			game_scene(t_game *game);
void			clear_window(t_mlx *mlx);
void			settings_destructor(t_settings *set);
void			game_destructor(t_game *game);
void			img_destructor(t_img *img);
void			init_mlx(t_mlx *mlx, char *filename);
void			parse_file(int fd, t_mlx *mlx);
int				parse_arguments(t_mlx *mlx, char *line);
void			game_set(t_mlx *mlx);
void			get_img_texture(t_mlx *mlx);
void			get_resolution(t_mlx *mlx, char *line);
void			get_color(t_mlx *mlx, char *line, char c);
void			get_texture(t_mlx *mlx, char *line);
void			set_player(t_mlx *mlx, int x, int y);
void			copy_map(t_mlx *mlx, char *line);
int				extension_xpm(char *file, char *ext);
int				is_ok_char(char c);
void			check_around(t_mlx *mlx, int x, int y, int len);
void			check_map(t_mlx *mlx);
void			check_settings(t_mlx *mlx);
int				raycasting(t_mlx *mlx);
void			wall_render(t_mlx *mlx, int x, double *pwd, t_vector_dir ray);
t_pos_img		get_draw_limits(t_mlx *mlx, int line_height);
t_pos_img		get_wall_texture(t_mlx *mlx, t_img texture, \
			double perp_wall_dist, t_vector_dir ray);
int				shoot_ray(t_mlx *mlx, t_vector_dir player, t_vector_dir ray, \
			double *perp_wall_dist);
t_vector_dir	get_delta_dist(t_vector_dir ray);
int				dda_algorithm(t_vector_dir *side_dist, t_vector_dir \
			*delta_dist, t_pos_img step, t_pos_img *map);
void			sprite_constructor(t_sprite *sprite, t_img texture, int x, \
			int y);
void			set_sprites(t_mlx *mlx);
int				count_sprites(char **map);
int				*get_sprite_order(t_mlx *mlx);
void			sort_sprites(int *order, double *dist, int nb_sprite);
void			sprite_render(t_mlx *mlx, double *z_buf);
t_vector_dir	get_sprite_transform(t_mlx *mlx, int i, int *sprite_order);
t_pos_img		get_sprite_dimension(t_mlx *mlx, t_vector_dir transform);
int				get_sprite_screen_x(t_mlx *mlx, t_vector_dir transform);
void			sprite_draw(t_mlx *mlx, int stripe, t_pos_img sprite,
			int s_screen_x);
int				key_press(int keycode, t_mlx *mlx);
int				close_window(t_mlx *mlx, int code);
int				close_error(t_mlx *mlx, char *error, void *ft_free,
			void (*f)(char**));
void			rotate_right(t_mlx *mlx);
void			rotate_left(t_mlx *mlx);
void			move_forward(t_mlx *mlx);
void			move_backward(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			move_left(t_mlx *mlx);
t_vector_dir	dir_vec(double x, double y);
t_pos_img		img_pos_vec(int x, int y);
void			my_pixel(t_mlx *mlx, int x, int y, int color);
int				rgb(int r, int g, int b, int t);
void			vertical_line(t_mlx *mlx, int x, t_pos_img limits, \
			int color);

#endif
