/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:56:36 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 17:59:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	control_char(char c, t_mlx *mlx)
{
	if (c == 'E')
		mlx->e += 1;
	if (c == 'P')
		mlx->p += 1;
	if (c == 'C')
		mlx->c += 1;
	if (c == 'S')
		mlx->s += 1;
}

void	check_map(char *line, t_mlx *mlx, int num, int i)
{
	int	len;

	len = ft_strlen(line);
	i = -1;
	if (line[0] != '1' || line[len - 1] != '1')
		close_error(mlx, ER_NOTSURR);
	while (line[++i])
	{
		if (is_ok_char(line[i]) == 0)
			close_error(mlx, ER_WRONGCHAR);
		control_char(line[i], mlx);
		if (mlx->e > 1 || mlx->p > 1)
			close_error(mlx, ER_MULTIC);
		if ((num == -1 || num == 0) && line[i] != '1')
		{
			free(line);
			close_error(mlx, ER_NOTSURR);
		}
	}
	mlx->mapx = i;
}

void	fill_map(int fd, char *filename, t_mlx *mlx, int i)
{
	char	*line;
	int		ret;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		close_error(mlx, ER_OPEN);
	mlx->map = ft_calloc(1, mlx->mapy * mlx->mapx);
	if (mlx->map == NULL)
		close_error(mlx, ER_MEMORY);
	i = 0;
	if (mlx->mapx > 1 && mlx->mapy > 1)
	{
		ret = get_next_line(fd, &line);
		while (ret)
		{
			mlx->map[i] = ft_strdup(line);
			i++;
			line = free_str(line);
			ret = get_next_line(fd, &line);
		}
		mlx->map[i] = ft_strdup(line);
		line = free_str(line);
	}
	close(fd);
}
