/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 16:50:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
/*
# if defined(__APPLE__)
#  include "key_macos.h"
# else
#  include "key_linux.h"
# endif
*/
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "exit_codes.h"
# include <fcntl.h>
# include <math.h>

# define WIN_NAME "So Long!"

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

/*
** FUNCTIONS TP EXIT
*/

int	red_cross(t_mlx *mlx);
int	close_window(t_mlx *mlx);

#endif
