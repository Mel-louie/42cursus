/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:50:33 by user42            #+#    #+#             */
/*   Updated: 2021/06/21 14:44:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	parse_file(int fd, t_mlx *mlx)
{
	char *line;
	int ret;
	
	while ((ret = get_next_line(fd, &line)))
	{
		printf("line: %s\n", line);
		free(line);
	}
	printf("line: %s\n", line);
	free(line);
	(void)mlx;
}

void	set_game(t_mlx *mlx, char *filename)
{
	int	fd;

	if (check_ext(filename, ".ber") == -1)
		close_error(mlx, ER_BAD_EXT);
	if ((fd = open(filename, O_RDONLY)) == -1)
		close_error(mlx, ER_OPEN);
	parse_file(fd, mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 800, 600, WIN_NAME);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

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
