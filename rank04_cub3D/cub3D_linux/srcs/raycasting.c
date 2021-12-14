/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:25:57 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/14 12:59:22 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			raycasting(t_mlx *mlx)
{
	int				x;
	double			z_buffer[mlx->set.res_x];
	t_vector_dir	ray;
	double			perp_wall_dist;

	x = 0;
	while (x < mlx->set.res_x)
	{
		ray.x = mlx->game.player_direction.x + mlx->game.plane.x * \
			(2 * x / (double)mlx->set.res_x - 1);
		ray.y = mlx->game.player_direction.y + mlx->game.plane.y * \
			(2 * x / (double)mlx->set.res_x - 1);
		wall_render(mlx, x, &perp_wall_dist, ray);
		z_buffer[x] = perp_wall_dist;
		x++;
	}
	sprite_render(mlx, z_buffer);
	return (1);
}

/*
** pwd is perpendicular wall distance
*/

void		wall_render(t_mlx *mlx, int x, double *pwd, t_vector_dir ray)
{
	t_pos_img	draw_limits;
	int			color;
	t_pos_img	w_texture;
	double		texture_pos;
	t_img		texture;

	if (shoot_ray(mlx, mlx->game.player, ray, pwd) == 0)
		texture = ray.x < 0 ? mlx->set.text_no : mlx->set.text_so;
	else
		texture = ray.y < 0 ? mlx->set.text_we : mlx->set.text_ea;
	draw_limits = get_draw_limits(mlx, (int)(mlx->set.res_y / *pwd));
	w_texture = get_wall_texture(mlx, texture, *pwd, ray);
	texture_pos = (draw_limits.x - mlx->set.res_y / 2 + (int)(mlx->set.res_y / \
		*pwd) / 2) * (1.0 * texture.height / (int)(mlx->set.res_y / *pwd));
	vertical_line(mlx, x, img_pos_vec(0, draw_limits.x), mlx->set.color_c);
	vertical_line(mlx, x, img_pos_vec(draw_limits.y, mlx->set.res_y), \
		mlx->set.color_f);
	while (draw_limits.x < draw_limits.y)
	{
		w_texture.y = (int)texture_pos & (texture.height - 1);
		texture_pos += 1.0 * texture.height / (int)(mlx->set.res_y / *pwd);
		color = texture.data[texture.height * w_texture.y + w_texture.x];
		my_pixel(mlx, x, draw_limits.x, color);
		draw_limits.x++;
	}
}

t_pos_img	get_draw_limits(t_mlx *mlx, int line_height)
{
	t_pos_img	draw_limits;

	draw_limits.x = -line_height / 2 + mlx->set.res_y / 2;
	if (draw_limits.x < 0)
		draw_limits.x = 0;
	draw_limits.y = line_height / 2 + mlx->set.res_y / 2;
	if (draw_limits.y >= mlx->set.res_y)
		draw_limits.y = mlx->set.res_y;
	return (draw_limits);
}

t_pos_img	get_wall_texture(t_mlx *mlx, t_img texture, \
	double perp_wall_dist, t_vector_dir ray)
{
	double		wall_x;
	t_pos_img	w_texture;
	int			side;

	if (ft_strcmp(texture.name, "north") == 0 \
		|| ft_strcmp(texture.name, "south") == 0)
		side = 0;
	else
		side = 1;
	if (side == 0)
		wall_x = mlx->game.player.y + perp_wall_dist * ray.y;
	else
		wall_x = mlx->game.player.x + perp_wall_dist * ray.x;
	wall_x -= floor(wall_x);
	w_texture.x = (int)(wall_x * (double)texture.width);
	if (side == 0 && ray.x > 0)
		w_texture.x = texture.width - w_texture.x - 1;
	if (side == 1 && ray.y < 0)
		w_texture.x = texture.width - w_texture.x - 1;
	return (w_texture);
}
