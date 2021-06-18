/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:56:03 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/10 18:14:14 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_file(int fd, t_mlx *mlx)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (!parse_arguments(mlx, line))
		{
			if (is_ok_char(line[0]) || line[0] == ' ')
				copy_map(mlx, line);
			else if (line && mlx->set.map != NULL)
			{
				free(line);
				close_error(mlx, ERR_MIS_INFO, NULL, NULL);
			}
			else if (line[0])
			{
				free(line);
				close_error(mlx, ERR_DATS, NULL, NULL);
			}
		}
		free(line);
	}
	check_settings(mlx);
}

int		parse_arguments(t_mlx *mlx, char *line)
{
	if (mlx->set.map != NULL)
		return (0);
	if (line[0] == 'R' && line[1] == ' ')
		get_resolution(mlx, line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		get_texture(mlx, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		get_texture(mlx, line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		get_texture(mlx, line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		get_texture(mlx, line);
	else if (line[0] == 'S' && line[1] == ' ')
		get_texture(mlx, line);
	else if (line[0] == 'F' && line[1] == ' ')
		get_color(mlx, line + 2, 'F');
	else if (line[0] == 'C' && line[1] == ' ')
		get_color(mlx, line + 2, 'C');
	else
		return (0);
	return (1);
}

void	game_set(t_mlx *mlx)
{
	if (mlx->set.player_dir == 'W')
		mlx->game.plane = dir_vec(-0.66, 0);
	else if (mlx->set.player_dir == 'E')
		mlx->game.plane = dir_vec(0.66, 0);
	else if (mlx->set.player_dir == 'S')
		mlx->game.plane = dir_vec(0, -0.66);
	else if (mlx->set.player_dir == 'N')
		mlx->game.plane = dir_vec(0, 0.66);
	set_sprites(mlx);
}

void	get_img_texture(t_mlx *mlx)
{
	mlx->set.text_no.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->set.path_no, &mlx->set.text_no.width, &mlx->set.text_no.height);
	mlx->set.text_no.data = (int*)mlx_get_data_addr(mlx->set.text_no.img_ptr, \
		&mlx->set.text_no.bpp, &mlx->set.text_no.s_l, &mlx->set.text_no.endian);
	mlx->set.text_no.name = "north";
	mlx->set.text_so.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->set.path_so, &mlx->set.text_so.width, &mlx->set.text_so.height);
	mlx->set.text_so.data = (int*)mlx_get_data_addr(mlx->set.text_so.img_ptr, \
		&mlx->set.text_so.bpp, &mlx->set.text_so.s_l, &mlx->set.text_so.endian);
	mlx->set.text_so.name = "south";
	mlx->set.text_ea.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->set.path_ea, &mlx->set.text_ea.width, &mlx->set.text_ea.height);
	mlx->set.text_ea.data = (int*)mlx_get_data_addr(mlx->set.text_ea.img_ptr, \
		&mlx->set.text_ea.bpp, &mlx->set.text_ea.s_l, &mlx->set.text_ea.endian);
	mlx->set.text_ea.name = "east";
	mlx->set.text_we.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->set.path_we, &mlx->set.text_we.width, &mlx->set.text_we.height);
	mlx->set.text_we.data = (int*)mlx_get_data_addr(mlx->set.text_we.img_ptr, \
		&mlx->set.text_we.bpp, &mlx->set.text_we.s_l, &mlx->set.text_we.endian);
	mlx->set.text_we.name = "west";
	mlx->set.text_s.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->set.path_s, &mlx->set.text_s.width, &mlx->set.text_s.height);
	mlx->set.text_s.data = (int*)mlx_get_data_addr(mlx->set.text_s.img_ptr, \
		&mlx->set.text_s.bpp, &mlx->set.text_s.s_l, &mlx->set.text_s.endian);
	mlx->set.text_s.name = "sprite";
}

void	init_mlx(t_mlx *mlx, char *filename)
{
	int fd;
	int	screen_x;
	int	screen_y;

	if (extension_xpm(filename, ".cub") == 0)
		close_error(mlx, ERR_INVALID_EXT, NULL, NULL);
	if ((fd = open(filename, O_RDONLY)) == -1)
		close_error(mlx, ERR_OPEN, NULL, NULL);
	parse_file(fd, mlx);
	mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx->mlx_ptr, &screen_x, &screen_y);
	init_screen(mlx, screen_x, screen_y);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr,
		mlx->set.res_x, mlx->set.res_y);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, \
	&mlx->img.s_l, &mlx->img.endian);
	get_img_texture(mlx);
	game_set(mlx);
	close(fd);
}
