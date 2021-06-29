/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:42:58 by user42            #+#    #+#             */
/*   Updated: 2021/06/29 18:02:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	display_moves(t_mlx *mlx)
{
	char	*str;

	mlx->moves++;
	str = ft_itoa(mlx->moves);
	ft_putstr_fd("\033[1;37mSO_LONG 🐟\t", 1);
	ft_putstr_fd("\033[0;37mmovement \033[1;37m#", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
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
