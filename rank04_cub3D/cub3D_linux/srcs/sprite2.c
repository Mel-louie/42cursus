/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:37:02 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/14 12:59:22 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** We create a table of order and distance of the sprites and fill them in.
** for each sprites in the map according to their distance
** in relation to the player (pos_x, pos_y).
** Then we sort these sprites from the closest to the furthest. (sort_sprites)
** after sort the sprites, do the projection calculs
** and draw them:
** the conditions in the if are:
** 1) it's in front of camera plane so you don't see things behind you
** 2) it's on the screen (left)
** 3) it's on the screen (right)
** 4) ZBuffer, with perpendicular distance
*/

void			sprite_render(t_mlx *mlx, double *z_buf)
{
	t_vector_dir	transform;
	t_pos_img		sprite;
	int				sprite_screen_x;
	int				stripe;
	int				i;

	i = 0;
	while (i < mlx->game.sprite_nb)
	{
		transform = get_sprite_transform(mlx, i, get_sprite_order(mlx));
		sprite = get_sprite_dimension(mlx, transform);
		sprite_screen_x = get_sprite_screen_x(mlx, transform);
		stripe = (-sprite.x / 2 + sprite_screen_x) < 0 \
			? 0 : -sprite.x / 2 + sprite_screen_x;
		while (stripe < ((sprite.x / 2 + sprite_screen_x) >= mlx->set.res_x
			? mlx->set.res_x - 1 : sprite.x / 2 + sprite_screen_x))
		{
			if (transform.y > 0 && stripe > 0 && stripe < mlx->set.res_x \
				&& transform.y < z_buf[stripe])
				sprite_draw(mlx, stripe, sprite, sprite_screen_x);
			stripe++;
		}
		i++;
	}
}

/*
** Project the sprite on the camera plane (in 2D): subtract the player
** position from the sprite position, then multiply the result with the
** inverse of the 2x2 camera matrix;
** To bring the sprite's coordinates to camera space, first subtract
** the player's position from the sprite's position, then you have the
** position of the sprite relative to the player.
** Then it has to be rotated so that the direction is relative to the
** player. The camera can also be distorded and has a certain size, so
** it isn't really a rotation, but a transformation. The transformation
** is done by multiplying the relative position of the sprite with the
** inverse of the camera matrix. The camera matrix is in our case
** [planeX   dirX]
** [planeY   dirY]
** And the inverse of a 2x2 matrix is very easy to calculate
**
** ____________1___________    [dirY      -dirX]
** (planeX*dirY-dirX*planeY) * [-planeY  planeX]
** Then you get the X and Y coordinate of the sprite in camera space,
** where Y is the depth inside the screen (in a true 3D engine, Z is
** the depth). To project it on screen, divide X through the depth, and
** then translate and scale it so that it's in pixel coordinates.
*/

t_vector_dir	get_sprite_transform(t_mlx *mlx, int i, int *sprite_order)
{
	t_vector_dir	transform;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;

	sprite_x = mlx->game.sprite_list[sprite_order[i]].x - mlx->game.player.x;
	sprite_y = mlx->game.sprite_list[sprite_order[i]].y - mlx->game.player.y;
	inv_det = 1.0 / (mlx->game.plane.x * mlx->game.player_direction.y
		- mlx->game.player_direction.x * mlx->game.plane.y);
	transform.x = inv_det * (mlx->game.player_direction.y * sprite_x
		- mlx->game.player_direction.x * sprite_y);
	transform.y = inv_det * (-mlx->game.plane.y * sprite_x
		+ mlx->game.plane.x * sprite_y);
	free(sprite_order);
	return (transform);
}

t_pos_img		get_sprite_dimension(t_mlx *mlx, t_vector_dir transform)
{
	t_pos_img sprite;

	if (transform.y != 0)
	{
		sprite.y = abs((int)(mlx->set.res_y / (transform.y)));
		sprite.x = abs((int)(mlx->set.res_y / (transform.y)));
	}
	else
	{
		sprite.y = abs((int)mlx->set.res_y);
		sprite.x = abs((int)mlx->set.res_y);
	}
	return (sprite);
}

int				get_sprite_screen_x(t_mlx *mlx, t_vector_dir transform)
{
	int		sprite_screen_x;

	if (transform.y != 0)
		sprite_screen_x = (int)((mlx->set.res_x / 2) \
			* (1 + transform.x / transform.y));
	else
		sprite_screen_x = (int)((mlx->set.res_x / 2) * (1 + transform.x));
	return (sprite_screen_x);
}

/*
** if ((color & 0x00FFFFFF) != 0): paint pixel if it's isn't black, black
** is the invisible color
*/

void			sprite_draw(t_mlx *mlx, int stripe, t_pos_img sprite,
	int s_screen_x)
{
	int		y;
	int		texture_y;
	int		color;
	int		texture_x;

	texture_x = (int)(256 * (stripe - (-sprite.x / 2 \
		+ s_screen_x)) * mlx->set.text_s.width / sprite.x) / 256;
	y = ((-sprite.y / 2 + mlx->set.res_y / 2) < 0 \
		? 0 : -sprite.y / 2 + mlx->set.res_y / 2);
	while (y < ((sprite.y / 2 + mlx->set.res_y / 2) >= mlx->set.res_y \
		? mlx->set.res_y - 1 : sprite.y / 2 + mlx->set.res_y / 2))
	{
		texture_y = (((y * 256 - mlx->set.res_y * 128 + sprite.y * 128) \
			* mlx->set.text_s.height) / sprite.y) / 256;
		color = mlx->set.text_s.data[mlx->set.text_s.width * texture_y \
			+ texture_x];
		if ((color & 0x00FFFFFF) != 0)
			my_pixel(mlx, stripe, y, color);
		y++;
	}
}
