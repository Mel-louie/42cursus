/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 17:35:59 by user42           ###   ########.fr       */
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

# define WIN_NAME "So Long!"

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

/*
** EVENTS
*/

int	key_press(int key, t_mlx *mlx);

/*
** FUNCTIONS TO EXIT
*/

int	red_cross(t_mlx *mlx);
int	close_window(t_mlx *mlx);

#endif
