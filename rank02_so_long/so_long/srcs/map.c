/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:56:36 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 18:42:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	make_colectibles(t_mlx *mlx)
{
	mlx->pl.nb_to_colec = mlx->c;
}

void	check_map(char *line, t_mlx *mlx, int num)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = -1;
	if (line[0] != '1' || line[len - 1] != '1')
		close_error(mlx, ER_NOTSURR);
	while (line[++i])
	{
		if (is_ok_char(line[i]) == 0)
			close_error(mlx, ER_WRONGCHAR);
		if (line[i] == 'E')
			mlx->e += 1;
		if (line[i] == 'P')
			mlx->p += 1;
		if (line[i] == 'C')
			mlx->c += 1;
		if (mlx->e > 1 || mlx->p > 1)
			close_error(mlx, ER_MULTIC);
		if ((num == -1 || num == 0) && line[i] != '1')
			close_error(mlx, ER_NOTSURR);
	}
	mlx->mapx = i;
	make_colectibles(mlx);
}

void	fill_map(int fd, char *filename, t_mlx *mlx, int i)
{
	char	*line;
	int		ret;

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
			i++;
			free(line);
			ret = get_next_line(fd, &line);
		}
		mlx->map[i] = ft_strdup(line);
		free(line);
	}
	close(fd);
}
