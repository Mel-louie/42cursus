/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:42:58 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 18:17:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	display_moves(t_mlx *mlx)
{
	char	*str;

	str = ft_itoa(mlx->moves);
	mlx_string_put(mlx->ptr, mlx->win, (mlx->mapx / 2) - 215,
		(mlx->mapy / 2) - 80, 0x00000000,
		"movement #");
	mlx_string_put(mlx->ptr, mlx->win, (mlx->mapx / 2) - 150,
		(mlx->mapy / 2) - 80, 0x00000000,
		str);
	str = free_str(str);
}

int	try_open(char *file)
{
	int	ret;

	ret = open(file, O_RDONLY);
	if (ret == -1)
		return (0);
	close(ret);
	return (1);
}
