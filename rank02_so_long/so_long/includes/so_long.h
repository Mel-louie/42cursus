/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/19 13:00:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** # if defined(__APPLE__)
** # include "key_macos.h"
** # else
** #  include "key_linux.h"
** # endif
*/

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "exit_codes.h"
# include "keys_codes.h"
# include <fcntl.h>

# define WIN_NAME "So Long!"

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

/*
** CHECKS
*/

int		check_ext(char *file_ext, char *ext);

/*
** EVENTS
*/

int	key_press(int key, t_mlx *mlx);

/*
** FUNCTIONS THAT EXIT
*/

int	red_cross(t_mlx *mlx);
int	close_window(t_mlx *mlx);
int	close_error(t_mlx *mlx, char *error);

#endif
