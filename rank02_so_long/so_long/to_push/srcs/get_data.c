/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:42:12 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 03:01:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_path(t_mlx *mlx)
{
	if (try_open("assets/floor.xpm") == 1)
		mlx->set.path_fl = ft_strdup("assets/floor.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/floor.xpm") == 1)
		mlx->set.path_wa = ft_strdup("assets/walls.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/floor.xpm") == 1)
		mlx->set.path_co = ft_strdup("assets/colect.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/floor.xpm") == 1)
		mlx->set.path_pl = ft_strdup("assets/player.xpm");
	else
		close_error(mlx, ER_TILES);
	if (try_open("assets/floor.xpm") == 1)
		mlx->set.path_en = ft_strdup("assets/end.xpm");
	else
		close_error(mlx, ER_TILES);
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
	mlx->set.t_pl.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_pl, &mlx->set.t_pl.width, &mlx->set.t_pl.height);
	mlx->set.t_pl.data = (int *)mlx_get_data_addr(mlx->set.t_pl.ptr, \
		&mlx->set.t_pl.bpp, &mlx->set.t_pl.s_l, &mlx->set.t_pl.endian);
	mlx->set.t_en.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_en, &mlx->set.t_en.width, &mlx->set.t_en.height);
	mlx->set.t_en.data = (int *)mlx_get_data_addr(mlx->set.t_en.ptr, \
		&mlx->set.t_en.bpp, &mlx->set.t_en.s_l, &mlx->set.t_en.endian);
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
