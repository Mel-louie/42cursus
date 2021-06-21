/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:50:33 by user42            #+#    #+#             */
/*   Updated: 2021/06/21 18:18:20 by user42           ###   ########.fr       */
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
	mlx->map = malloc(sizeof(char) * (mlx->map_y * mlx->map_x));
	if (mlx->map == NULL)
		close_error(mlx, ER_MEMORY);
	i = 0;
	if (mlx->map_x > 1 && mlx->map_y > 1)
	{
		ret = get_next_line(fd, &line);
		while (ret)
		{
			mlx->map[i] = ft_strdup(line);
			printf("mlx->map: %s\n", mlx->map[i]);
			i++;
			free(line);
			ret = get_next_line(fd, &line);
		}
		mlx->map[i] = ft_strdup(line);
		printf("mlx->map: %s\n", mlx->map[i]);
		free(line);
	}
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
	mlx->map_y = num + 1;
	check_map(line, mlx, -1);
	free(line);
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
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 800, 600, WIN_NAME);
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
