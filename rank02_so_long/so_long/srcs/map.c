/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:56:36 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 11:10:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		if (mlx->e > 1 || mlx->p > 1)
			close_error(mlx, ER_MULTIC);
		if ((num == -1 || num == 0) && line[i] != '1')
			close_error(mlx, ER_NOTSURR);
	}
	mlx->mapx = i;
}
