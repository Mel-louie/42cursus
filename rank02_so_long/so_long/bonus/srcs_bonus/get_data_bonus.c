/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:42:12 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 02:59:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	get_path_player(t_mlx *mlx)
{
	if (try_open("assets/player.xpm") == 1)
		mlx->set.path_pl1 = ft_strdup("assets/player.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/player2.xpm") == 1)
		mlx->set.path_pl2 = ft_strdup("assets/player2.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/player3.xpm") == 1)
		mlx->set.path_pl3 = ft_strdup("assets/player3.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/player4.xpm") == 1)
		mlx->set.path_pl4 = ft_strdup("assets/player4.xpm");
	else
		close_error(mlx, ER_TILES);
}

void	get_path(t_mlx *mlx)
{
	if (try_open("assets/floor.xpm") == 1)
		mlx->set.path_fl = ft_strdup("assets/floor.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/walls.xpm") == 1)
		mlx->set.path_wa = ft_strdup("assets/walls.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/colect.xpm") == 1)
		mlx->set.path_co = ft_strdup("assets/colect.xpm");
	else
		close_error(mlx, ER_TILES);
	get_path_player(mlx);
	if (try_open("assets/end.xpm") == 1)
		mlx->set.path_en = ft_strdup("assets/end.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/enemy.xpm") == 1)
		mlx->set.path_enem = ft_strdup("assets/enemy.xpm");
	else
		close_error(mlx, ER_TILES);
}

void	get_player_tiles(t_mlx *mlx)
{
	mlx->set.t_pl1.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_pl1, &mlx->set.t_pl1.width, &mlx->set.t_pl1.height);
	mlx->set.t_pl1.data = (int *)mlx_get_data_addr(mlx->set.t_pl1.ptr, \
		&mlx->set.t_pl1.bpp, &mlx->set.t_pl1.s_l, &mlx->set.t_pl1.endian);
	mlx->set.t_pl2.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_pl2, &mlx->set.t_pl2.width, &mlx->set.t_pl2.height);
	mlx->set.t_pl2.data = (int *)mlx_get_data_addr(mlx->set.t_pl2.ptr, \
		&mlx->set.t_pl2.bpp, &mlx->set.t_pl2.s_l, &mlx->set.t_pl2.endian);
	mlx->set.t_pl3.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_pl3, &mlx->set.t_pl3.width, &mlx->set.t_pl3.height);
	mlx->set.t_pl3.data = (int *)mlx_get_data_addr(mlx->set.t_pl3.ptr, \
		&mlx->set.t_pl3.bpp, &mlx->set.t_pl3.s_l, &mlx->set.t_pl3.endian);
	mlx->set.t_pl4.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_pl4, &mlx->set.t_pl4.width, &mlx->set.t_pl4.height);
	mlx->set.t_pl4.data = (int *)mlx_get_data_addr(mlx->set.t_pl4.ptr, \
		&mlx->set.t_pl4.bpp, &mlx->set.t_pl4.s_l, &mlx->set.t_pl4.endian);
}

void	get_img_texture(t_mlx *mlx)
{
	mlx->set.t_fl.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_fl, &mlx->set.t_fl.width, &mlx->set.t_fl.height);
	mlx->set.t_fl.data = (int *)mlx_get_data_addr(mlx->set.t_fl.ptr, \
		&mlx->set.t_fl.bpp, &mlx->set.t_fl.s_l, &mlx->set.t_fl.endian);
	mlx->set.t_wa.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_wa, &mlx-> set.t_wa.width, &mlx->set.t_wa.height);
	mlx->set.t_wa.data = (int *)mlx_get_data_addr(mlx->set.t_wa.ptr, \
		&mlx->set.t_wa.bpp, &mlx->set.t_wa.s_l, &mlx->set.t_wa.endian);
	mlx->set.t_co.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_co, &mlx->set.t_co.width, &mlx->set.t_co.height);
	mlx->set.t_co.data = (int *)mlx_get_data_addr(mlx->set.t_co.ptr, \
		&mlx->set.t_co.bpp, &mlx->set.t_co.s_l, &mlx->set.t_co.endian);
	mlx->set.t_en.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_en, &mlx->set.t_en.width, &mlx->set.t_en.height);
	mlx->set.t_en.data = (int *)mlx_get_data_addr(mlx->set.t_en.ptr, \
		&mlx->set.t_en.bpp, &mlx->set.t_en.s_l, &mlx->set.t_en.endian);
	mlx->set.t_enem.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_enem, &mlx->set.t_enem.width, &mlx->set.t_enem.height);
	mlx->set.t_enem.data = (int *)mlx_get_data_addr(mlx->set.t_enem.ptr, \
		&mlx->set.t_enem.bpp, &mlx->set.t_enem.s_l, &mlx->set.t_enem.endian);
	get_player_tiles(mlx);
}

void	parse_file(int fd, t_mlx *mlx, int i)
{
	char	*line;
	int		ret;
	int		num;
	int		size;

	num = 0;
	i = -1;
	ret = get_next_line(fd, &line);
	while (ret)
	{
		size = ft_strlen(line);
		check_map(line, mlx, num, i);
		free(line);
		num++;
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) != size)
		{
			free(line);
			close_error(mlx, ER_REC);
		}
	}
	mlx->mapy = num + 1;
	check_map(line, mlx, -1, i);
	free(line);
	check_char(mlx);
}
