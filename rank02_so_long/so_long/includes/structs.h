/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:01:17 by user42            #+#    #+#             */
/*   Updated: 2021/06/28 22:05:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** STRUCTS
*/

enum {UP, DOWN, RIGHT, LEFT};

typedef struct s_elem_colec	t_elem_colec;

typedef struct s_elem_colec
{
	int				touched;
	int				colecx;
	int				colecy;
	t_elem_colec	*next;
}				t_elem_colec;

typedef struct s_lst_colec
{
	t_elem_colec	*first;
}				t_lst_colec;

typedef struct s_exit
{
	int			exitx;
	int			exity;
}				t_exit;

typedef struct s_player
{
	int			posx;
	int			posy;
	int			direction;
}				t_player;

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			s_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
	char		*name;
}				t_img;

typedef struct s_assets
{
	char		*path_fl;
	char		*path_wa;
	char		*path_co;
	char		*path_pl;
	char		*path_en;
	t_img		t_fl;
	t_img		t_wa;
	t_img		t_co;
	t_img		t_pl;
	t_img		t_en;
}				t_assets;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			p;
	int			e;
	int			c;
	int			mapx;
	int			mapy;
	char		**map;
	t_img		img;
	t_assets	set;
	t_player	pl;
	t_exit		pos;
	t_lst_colec	lst_colec;
}				t_mlx;

#endif