/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:11:37 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 13:46:08 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_resolution(t_mlx *mlx, char *line)
{
	char	**tab;

	if (mlx->set.res_x == -1)
	{
		tab = ft_split(line, ' ');
		if (len_tab(tab) != 3)
			close_error(mlx, ERR_DATS, tab, free_tab);
		if (strisalpha(tab[1]) || strisalpha(tab[2]))
			close_error(mlx, ERR_RES, tab, free_tab);
		mlx->set.res_x = ft_atoi(tab[1]);
		mlx->set.res_y = ft_atoi(tab[2]);
		free_tab(tab);
		if (mlx->set.res_x < 50 || mlx->set.res_y < 50)
			close_error(mlx, ERR_RESO_SMALL, NULL, NULL);
	}
	else
	{
		free(line);
		close_error(mlx, ERR_DUP_RES, NULL, NULL);
	}
}

void	get_color(t_mlx *mlx, char *line, char c)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (len_tab(tab) != 1)
		close_error(mlx, ERR_NB_COLOR, tab, free_tab);
	free_tab(tab);
	tab = ft_split(line, ',');
	if (len_tab(tab) != 3)
		close_error(mlx, ERR_NB_COLOR, tab, free_tab);
	if (strisalpha(tab[0]) || strisalpha(tab[1]) || strisalpha(tab[2]))
		close_error(mlx, ERR_COLOR, tab, free_tab);
	if (ft_atoi(tab[0]) < 0 || ft_atoi(tab[0]) > 255 || ft_atoi(tab[1]) < 0
		|| ft_atoi(tab[1]) > 255 || ft_atoi(tab[2]) < 0
		|| ft_atoi(tab[2]) > 255)
		close_error(mlx, ERR_VAL_COLOR, NULL, NULL);
	if (c == 'C' && mlx->set.color_c == -1)
		mlx->set.color_c = rgb(ft_atoi(tab[0]), ft_atoi(tab[1]),
			ft_atoi(tab[2]), 0);
	else if (mlx->set.color_f == -1)
		mlx->set.color_f = rgb(ft_atoi(tab[0]), ft_atoi(tab[1]),
			ft_atoi(tab[2]), 0);
	else
		close_error(mlx, ERR_DUB_COLOR, tab, free_tab);
	free_tab(tab);
}

void	get_texture(t_mlx *mlx, char *line)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (len_tab(tab) != 2)
		close_error(mlx, ERR_NB_TEX, tab, free_tab);
	if (!extension_xpm(tab[1], ".xpm"))
		close_error(mlx, ERR_OPEN_TEX, tab, free_tab);
	if ((try_open(tab[1])) == 0)
		close_error(mlx, ERR_OPEN_TEX, tab, free_tab);
	if (tab[0][0] == 'N' && mlx->set.path_no == NULL)
		mlx->set.path_no = ft_strdup(tab[1]);
	else if (tab[0][0] == 'S' && tab[0][1] == 'O' && mlx->set.path_so == NULL)
		mlx->set.path_so = ft_strdup(tab[1]);
	else if (tab[0][0] == 'W' && mlx->set.path_we == NULL)
		mlx->set.path_we = ft_strdup(tab[1]);
	else if (tab[0][0] == 'E' && mlx->set.path_ea == NULL)
		mlx->set.path_ea = ft_strdup(tab[1]);
	else if (tab[0][0] == 'S' && tab[0][1] == '\0' && mlx->set.path_s == NULL)
		mlx->set.path_s = ft_strdup(tab[1]);
	else
		close_error(mlx, ERR_DUP_TEX, tab, free_tab);
	free_tab(tab);
}

void	set_player(t_mlx *mlx, int x, int y)
{
	if (!mlx->set.player_dir)
	{
		mlx->set.player_dir = mlx->set.map[x][y];
		mlx->game.player.x = x + 0.5;
		mlx->game.player.y = y + 0.5;
		if (mlx->set.player_dir == 'W')
			mlx->game.player_direction = dir_vec(0, -1);
		else if (mlx->set.player_dir == 'E')
			mlx->game.player_direction = dir_vec(0, 1);
		else if (mlx->set.player_dir == 'S')
			mlx->game.player_direction = dir_vec(1, 0);
		else if (mlx->set.player_dir == 'N')
			mlx->game.player_direction = dir_vec(-1, 0);
		mlx->set.map[x][y] = '0';
	}
	else
		close_error(mlx, ERR_PLAYER_MANY, NULL, NULL);
}

void	copy_map(t_mlx *mlx, char *line)
{
	int		len;
	char	**tmp;

	if (!mlx->set.map)
	{
		if (!(mlx->set.map = (char**)malloc(sizeof(char*) * 1)))
			close_error(mlx, ERR_MEM_ALLOC, NULL, NULL);
		mlx->set.map[0] = 0;
	}
	len = 0;
	while (mlx->set.map[len])
		len++;
	if (!(tmp = (char**)malloc(sizeof(char *) * (len + 2))))
		close_error(mlx, ERR_MEM_ALLOC, NULL, NULL);
	len = 0;
	while (mlx->set.map[len])
	{
		tmp[len] = ft_strdup(mlx->set.map[len]);
		len++;
	}
	tmp[len] = ft_strdup(line);
	tmp[len + 1] = 0;
	free_tab(mlx->set.map);
	mlx->set.map = tmp;
}
