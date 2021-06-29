/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:04:53 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 22:49:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	check_char(t_mlx *mlx)
{
	if (mlx->e == 0)
		close_error(mlx, ER_NO_EX);
	if (mlx->p == 0)
		close_error(mlx, ER_NO_PL);
	if (mlx->c == 0)
		close_error(mlx, ER_NO_CO);
	if (mlx->s == 0)
		close_error(mlx, ER_NO_EN);
}

int	is_ok_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'S')
		return (1);
	return (0);
}

int	check_ext(char *file_ext, char *ext)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file_ext);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (file_ext[len_file] != ext[len_ext])
			return (-1);
		len_file--;
		len_ext--;
	}
	return (0);
}

int	check_tiles(t_mlx *mlx)
{
	if (check_ext("assets/floor.xpm", ".xpm") == -1 \
		|| check_ext("assets/walls.xpm", ".xpm") == -1 \
		|| check_ext("assets/colect.xpm", ".xpm") == -1 \
		|| check_ext("assets/player.xpm", ".xpm") == -1 \
		|| check_ext("assets/player2.xpm", ".xpm") == -1 \
		|| check_ext("assets/player3.xpm", ".xpm") == -1 \
		|| check_ext("assets/player4.xpm", ".xpm") == -1 \
		|| check_ext("assets/end.xpm", ".xpm") == -1 \
		|| check_ext("assets/enemy.xpm", ".xpm") == -1)
		return (-2);
	mlx->floor = try_open("assets/floor.xpm");
	mlx->walls = try_open("assets/walls.xpm");
	mlx->colect = try_open("assets/colect.xpm");
	mlx->player1 = try_open("assets/player.xpm");
	mlx->player2 = try_open("assets/player2.xpm");
	mlx->player3 = try_open("assets/player3.xpm");
	mlx->player4 = try_open("assets/player4.xpm");
	mlx->end = try_open("assets/end.xpm");
	mlx->enemy = try_open("assets/enemy.xpm");
	if ((mlx->floor || mlx->walls || mlx->colect || mlx->player1
			|| mlx->player1 || mlx->player3 || mlx->player3
			|| mlx->end || mlx->enemy) == 0)
		return (-1);
	return (0);
}
