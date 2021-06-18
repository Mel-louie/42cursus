/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:26:54 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/03 08:58:44 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** When the game ends, clear anad free all for not leak
*/

void	settings_destructor(t_settings *set)
{
	int i;

	if (set->path_ea != NULL)
		free(set->path_ea);
	if (set->path_no)
		free(set->path_no);
	if (set->path_we)
		free(set->path_we);
	if (set->path_so)
		free(set->path_so);
	if (set->path_s)
		free(set->path_s);
	if (set->map)
	{
		i = 0;
		while (set->map[i])
		{
			free(set->map[i]);
			set->map[i] = NULL;
			i++;
		}
		free(set->map);
		set->map = NULL;
	}
}

void	game_destructor(t_game *game)
{
	if (game->sprite_list)
	{
		free(game->sprite_list);
		game->sprite_list = NULL;
	}
}

void	img_destructor(t_img *img)
{
	free(img->img_ptr);
}

void	clear_window(t_mlx *mlx)
{
	settings_destructor(&mlx->set);
	game_destructor(&mlx->game);
	free(mlx->mlx_ptr);
}
