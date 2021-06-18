/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:02:16 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/10 18:23:18 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** where I init the game, parse, and launch algorithm
*/

int		run_game(t_mlx *mlx)
{
	raycasting(mlx);
	if (mlx->save == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
								mlx->img.img_ptr, 0, 0);
		mlx_do_sync(mlx->mlx_ptr);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	mlx.save = 0;
	if (argc < 2 || argc > 3 || (argc == 3 && ft_strcmp(argv[2], "--save")))
	{
		ft_putstr_fd(ERR_ARGS, 2);
		ft_putstr_fd("Mini 2, max 3, like this: ./Cub3D map.cub [--save]\n", 2);
		return (EXIT_FAILURE);
	}
	if (argc == 3)
		mlx.save = 1;
	init_game(&mlx);
	init_mlx(&mlx, argv[1]);
	if (mlx.save == 1)
	{
		run_game(&mlx);
		save_bmp(&mlx);
	}
	mlx_loop_hook(mlx.mlx_ptr, run_game, &mlx);
	mlx_hook(mlx.win_ptr, 2, (1L << 0), key_press, &mlx);
	mlx_hook(mlx.win_ptr, 33, (1L << 17), red_cross, &mlx);
	mlx_loop(mlx.mlx_ptr);
	close_window(&mlx, 0);
	return (EXIT_SUCCESS);
}
