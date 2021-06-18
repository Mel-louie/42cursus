/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:55:52 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/07 16:14:10 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sprite_constructor(t_sprite *sprite, t_img texture, int x, int y)
{
	sprite->texture = texture;
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
}

void	set_sprites(t_mlx *mlx)
{
	int j;
	int i;
	int x;

	mlx->game.sprite_nb = count_sprites(mlx->set.map);
	if (!(mlx->game.sprite_list = malloc(sizeof(t_sprite) \
		* (mlx->game.sprite_nb))))
		close_error(mlx, ERR_MEM_ALLOC, NULL, NULL);
	i = 0;
	x = 0;
	while (mlx->set.map[i])
	{
		j = 0;
		while (mlx->set.map[i][j])
		{
			if (mlx->set.map[i][j] == '2')
			{
				sprite_constructor(&mlx->game.sprite_list[x], \
					mlx->set.text_s, i, j);
				x++;
			}
			j++;
		}
		i++;
	}
}

int		count_sprites(char **map)
{
	int i;
	int j;
	int sprites_nb;

	i = 0;
	sprites_nb = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				sprites_nb++;
			j++;
		}
		i++;
	}
	return (sprites_nb);
}

/*
** sort sprites from far to close
** sort_sprites: sorted the sprites based on distance
*/

int		*get_sprite_order(t_mlx *mlx)
{
	int		*sprite_order;
	double	sprite_distance[mlx->game.sprite_nb];
	int		i;

	if (!(sprite_order = (int*)malloc(sizeof(int) * mlx->game.sprite_nb)))
	{
		ft_putstr_fd(ERR_MEM_ALLOC, 2);
		close_window(mlx, 7);
	}
	i = 0;
	while (i < mlx->game.sprite_nb)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((mlx->game.player.x \
			- mlx->game.sprite_list[i].x) \
			* (mlx->game.player.x - mlx->game.sprite_list[i].x) \
			+ (mlx->game.player.y - mlx->game.sprite_list[i].y) \
			* (mlx->game.player.y - mlx->game.sprite_list[i].y));
		i++;
	}
	sort_sprites(sprite_order, sprite_distance, mlx->game.sprite_nb);
	return (sprite_order);
}

void	sort_sprites(int *order, double *dist, int nb_sprite)
{
	int		sorted;
	int		j;
	double	tmp_dist;
	int		tmp;

	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		j = 0;
		while (j < nb_sprite - 1)
		{
			if (dist[j] < dist[j + 1])
			{
				tmp_dist = dist[j + 1];
				dist[j + 1] = dist[j];
				dist[j] = tmp_dist;
				tmp = order[j + 1];
				order[j + 1] = order[j];
				order[j] = tmp;
				sorted = 1;
			}
			j++;
		}
	}
}
