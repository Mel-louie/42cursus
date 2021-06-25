/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:50:33 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 16:10:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	run_game(t_mlx *mlx)
{
	draw_map(mlx);
	mlx_do_sync(mlx->ptr);
	return (0);
}

void	set_game(t_mlx *mlx, char *filename)
{
	int	fd;
	int	i;

	i = 0;
	if (check_ext(filename, ".ber") == -1)
		close_error(mlx, ER_BAD_EXT);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		close_error(mlx, ER_OPEN);
	parse_file(fd, mlx);
	fill_map(fd, filename, mlx, i);
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
	mlx.c = 0;
	if (ac < 2 || ac > 3)
	{
		ft_putstr_fd(ERR_ARG, 2);
		return (1);
	}
	set_game(&mlx, av[1]);
	mlx_loop_hook(mlx.ptr, run_game, &mlx);
	mlx_hook(mlx.win, 2, (1L << 0), key_press, &mlx);
	mlx_hook(mlx.win, 33, (1L << 17), red_cross, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
