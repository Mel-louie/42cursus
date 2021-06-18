/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:02:21 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/09 14:01:11 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		extension_xpm(char *file, char *ext)
{
	int len;
	int len_ext;

	len = ft_strlen(file);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (file[len] != ext[len_ext])
			return (0);
		len--;
		len_ext--;
	}
	return (1);
}

int		is_ok_char(char c)
{
	if (c == '0' || c == '1' || c == '2'
		|| c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

void	check_around(t_mlx *mlx, int x, int y, int len)
{
	if (x == 0 || x == len - 1 || !is_ok_char(mlx->set.map[x - 1][y])
			|| !is_ok_char(mlx->set.map[x][y - 1])
			|| !is_ok_char(mlx->set.map[x + 1][y])
			|| !is_ok_char(mlx->set.map[x][y + 1])
			|| !is_ok_char(mlx->set.map[x + 1][y + 1])
			|| !is_ok_char(mlx->set.map[x - 1][y - 1])
			|| !is_ok_char(mlx->set.map[x + 1][y - 1])
			|| !is_ok_char(mlx->set.map[x - 1][y + 1]))
		close_error(mlx, ERR_MAP, NULL, NULL);
}

void	check_map(t_mlx *mlx)
{
	int x;
	int y;
	int len;

	x = -1;
	len = 0;
	while (mlx->set.map[len])
		len++;
	while (mlx->set.map[++x])
	{
		y = 0;
		while (mlx->set.map[x][y])
		{
			if (!(is_ok_char(mlx->set.map[x][y]) || mlx->set.map[x][y] == ' '))
				close_error(mlx, ERR_WRONG_CHAR, NULL, NULL);
			if (mlx->set.map[x][y] == '0' || mlx->set.map[x][y] == 'N'
				|| mlx->set.map[x][y] == 'S' || mlx->set.map[x][y] == 'E'
				|| mlx->set.map[x][y] == 'W' || mlx->set.map[x][y] == '2')
				check_around(mlx, x, y, len);
			if (mlx->set.map[x][y] == 'N' || mlx->set.map[x][y] == 'S'
				|| mlx->set.map[x][y] == 'E' || mlx->set.map[x][y] == 'W')
				set_player(mlx, x, y);
			y++;
		}
	}
}

void	check_settings(t_mlx *mlx)
{
	if (mlx->set.res_x == -1 || mlx->set.res_y == -1 || !mlx->set.path_ea
		|| !mlx->set.path_no || !mlx->set.path_s || !mlx->set.path_so
		|| !mlx->set.path_we || mlx->set.color_c == -1 || mlx->set.color_f == -1
		|| !mlx->set.map)
		close_error(mlx, ERR_MISS_DATS, NULL, NULL);
	check_map(mlx);
	if (!mlx->set.player_dir)
		close_error(mlx, ERR_PLAYER, NULL, NULL);
}
