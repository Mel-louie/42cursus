/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:50:33 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 13:32:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(int fd, char *filename, t_mlx *mlx)
{
	char	*line;
	int		ret;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		close_error(mlx, ER_OPEN);
	mlx->map = malloc(sizeof(char) * (mlx->mapy * mlx->mapx));
	if (mlx->map == NULL)
		close_error(mlx, ER_MEMORY);
	i = 0;
	if (mlx->mapx > 1 && mlx->mapy > 1)
	{
		ret = get_next_line(fd, &line);
		while (ret)
		{
			mlx->map[i] = ft_strdup(line);
	//		printf("mlx->map: %s\n", mlx->map[i]);
			i++;
			free(line);
			ret = get_next_line(fd, &line);
		}
		mlx->map[i] = ft_strdup(line);
	//	printf("mlx->map: %s\n", mlx->map[i]);
		free(line);
	}
	close(fd);
}

void	parse_file(int fd, t_mlx *mlx)
{
	char	*line;
	int		ret;
	int		num;

	num = 0;
	ret = get_next_line(fd, &line);
	while (ret)
	{
		check_map(line, mlx, num);
		free(line);
		num++;
		ret = get_next_line(fd, &line);
	}
	mlx->mapy = num + 1;
	check_map(line, mlx, -1);
	free(line);
}

void	get_path(t_mlx *mlx)
{
	if (check_tiles() == -1)
		close_error(mlx, ER_TILES);
	if (check_tiles() == -2)
		close_error(mlx, ER_BAD_EXT);
	mlx->set.path_fl = ft_strdup("assets/floor.xpm");
	mlx->set.path_wa = ft_strdup("assets/walls.xpm");
	mlx->set.path_co = ft_strdup("assets/colect.xpm");
	mlx->set.path_pl = ft_strdup("assets/player.xpm");
	mlx->set.path_en = ft_strdup("assets/end.xpm");
}

void	get_img_texture(t_mlx *mlx)
{
	mlx->set.text_fl.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_fl, &mlx->set.text_fl.width, &mlx->set.text_fl.height);
	mlx->set.text_fl.data = (int *)mlx_get_data_addr(mlx->set.text_fl.ptr, \
		&mlx->set.text_fl.bpp, &mlx->set.text_fl.s_l, &mlx->set.text_fl.endian);
	mlx->set.text_fl.name = "floor";
	mlx->set.text_wa.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_wa, &mlx-> set.text_wa.width, &mlx->set.text_wa.height);
	mlx->set.text_wa.data = (int *)mlx_get_data_addr(mlx->set.text_wa.ptr, \
		&mlx->set.text_wa.bpp, &mlx->set.text_wa.s_l, &mlx->set.text_wa.endian);
	mlx->set.text_wa.name = "walls";
	mlx->set.text_co.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_co, &mlx->set.text_co.width, &mlx->set.text_co.height);
	mlx->set.text_co.data = (int *)mlx_get_data_addr(mlx->set.text_co.ptr, \
		&mlx->set.text_co.bpp, &mlx->set.text_co.s_l, &mlx->set.text_co.endian);
	mlx->set.text_co.name = "colect";
	mlx->set.text_pl.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_pl, &mlx->set.text_pl.width, &mlx->set.text_pl.height);
	mlx->set.text_pl.data = (int *)mlx_get_data_addr(mlx->set.text_pl.ptr, \
		&mlx->set.text_pl.bpp, &mlx->set.text_pl.s_l, &mlx->set.text_pl.endian);
	mlx->set.text_pl.name = "player";
	mlx->set.text_en.ptr = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->set.path_en, &mlx->set.text_en.width, &mlx->set.text_en.height);
	mlx->set.text_en.data = (int *)mlx_get_data_addr(mlx->set.text_en.ptr, \
		&mlx->set.text_en.bpp, &mlx->set.text_en.s_l, &mlx->set.text_en.endian);
	mlx->set.text_en.name = "end";
}

void	set_game(t_mlx *mlx, char *filename)
{
	int	fd;

	if (check_ext(filename, ".ber") == -1)
		close_error(mlx, ER_BAD_EXT);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		close_error(mlx, ER_OPEN);
	parse_file(fd, mlx);
	fill_map(fd, filename, mlx);
	get_path(mlx);
	mlx->ptr = mlx_init();
	window_size(mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->mapx, mlx->mapy, WIN_NAME);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->mapx, mlx->mapy);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
		&mlx->img.s_l, &mlx->img.endian);
	get_img_texture(mlx);
	
	close(fd);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.p = 0;
	mlx.e = 0;
	if (ac < 2 || ac > 3)
	{
		ft_putstr_fd(ERR_ARG, 2);
		return (1);
	}
	set_game(&mlx, av[1]);
	mlx_hook(mlx.win, 2, (1L << 0), key_press, &mlx);
	mlx_hook(mlx.win, 33, (1L << 17), red_cross, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
