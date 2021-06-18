/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:30:19 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 12:35:37 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** shoot_ray returns the side the ray hit.
** Takes the player position, a ray and a pointer to
*/

int				shoot_ray(t_mlx *mlx, t_vector_dir player, t_vector_dir ray, \
	double *perp_wall_dist)
{
	t_vector_dir	side_dist;
	t_vector_dir	delta_dist;
	t_pos_img		map;
	t_pos_img		step;
	int				side;

	map.x = (int)player.x;
	map.y = (int)player.y;
	delta_dist = get_delta_dist(ray);
	step.x = (ray.x < 0) ? -1 : 1;
	step.y = (ray.y < 0) ? -1 : 1;
	side_dist.x = (ray.x < 0) ? (player.x - map.x) * delta_dist.x \
		: (map.x + 1.0 - player.x) * delta_dist.x;
	side_dist.y = (ray.y < 0) ? (player.y - map.y) * delta_dist.y \
		: (map.y + 1.0 - player.y) * delta_dist.y;
	while (mlx->set.map[map.x][map.y] != '1')
		side = dda_algorithm(&side_dist, &delta_dist, step, &map);
	if (side == 0)
		*perp_wall_dist = (map.x - player.x + (1 - step.x) / 2) / ray.x;
	else
		*perp_wall_dist = (map.y - player.y + (1 - step.y) / 2) / ray.y;
	return (side);
}

t_vector_dir	get_delta_dist(t_vector_dir ray)
{
	t_vector_dir	delta_dist;

	if (ray.y == 0)
		delta_dist.x = 0;
	else if (ray.x == 0)
		delta_dist.x = 1;
	else
		delta_dist.x = fabs(1 / ray.x);
	if (ray.x == 0)
		delta_dist.y = 0;
	else if (ray.y == 0)
		delta_dist.y = 1;
	else
		delta_dist.y = fabs(1 / ray.y);
	return (delta_dist);
}

/*
** Digital Diffencial Analysis algorithm
*/

int				dda_algorithm(t_vector_dir *side_dist, t_vector_dir \
	*delta_dist, t_pos_img step, t_pos_img *map)
{
	if (side_dist->x < side_dist->y)
	{
		side_dist->x += delta_dist->x;
		map->x += step.x;
		return (0);
	}
	else
	{
		side_dist->y += delta_dist->y;
		map->y += step.y;
		return (1);
	}
}
