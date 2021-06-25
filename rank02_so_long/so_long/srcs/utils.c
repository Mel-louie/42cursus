/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:42:58 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 13:09:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	try_open(char *file)
{
	int	ret;

	ret = open(file, O_RDONLY);
	if (ret == -1)
		return (0);
	close(ret);
	return (1);
}
