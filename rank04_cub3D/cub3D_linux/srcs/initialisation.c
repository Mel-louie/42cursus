/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:52:47 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 12:24:42 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_game(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->filename = NULL;
	initial_settings(&mlx->set);
	init_img(&mlx->img);
	game_scene(&mlx->game);
}

void		initial_settings(t_settings *set)
{
	set->path_ea = NULL;
	set->path_no = NULL;
	set->path_we = NULL;
	set->path_so = NULL;
	set->path_s = NULL;
	init_img(&set->text_ea);
	init_img(&set->text_we);
	init_img(&set->text_no);
	init_img(&set->text_so);
	init_img(&set->text_s);
	set->res_x = -1;
	set->res_y = -1;
	set->color_f = -1;
	set->color_c = -1;
	set->map = NULL;
	set->player_dir = 0;
}

void		init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->data = NULL;
	img->s_l = 0;
	img->bpp = 0;
	img->endian = 0;
	img->name = NULL;
}

void		game_scene(t_game *game)
{
	game->plane.x = 0;
	game->plane.y = 0;
	game->sprite_list = NULL;
	game->sprite_nb = 0;
	game->player.x = 0;
	game->player.y = 0;
}
