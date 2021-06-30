/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:01:17 by user42            #+#    #+#             */
/*   Updated: 2021/06/30 21:07:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

/*
** STRUCTS
*/

enum {UP, DOWN, RIGHT, LEFT};

typedef struct s_elem_enemy	t_elem_enemy;

typedef struct s_elem_enemy
{
	int				touched;
	int				enemyx;
	int				enemyy;
	t_elem_enemy	*next;
}				t_elem_enemy;

typedef struct s_lst_enemy
{
	t_elem_enemy	*first;
}				t_lst_enemy;

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

typedef struct s_elem_exit	t_elem_exit;

typedef struct s_elem_exit
{
	int				exitx;
	int				exity;
	t_elem_exit		*next;
}				t_elem_exit;

typedef struct s_lst_exit
{
	t_elem_exit	*first;
}				t_lst_exit;

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
	char		*path_pl1;
	char		*path_pl2;
	char		*path_pl3;
	char		*path_pl4;
	char		*path_en;
	char		*path_enem;
	t_img		t_fl;
	t_img		t_wa;
	t_img		t_co;
	t_img		t_pl1;
	t_img		t_pl2;
	t_img		t_pl3;
	t_img		t_pl4;
	t_img		t_en;
	t_img		t_enem;
}				t_assets;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			p;
	int			e;
	int			c;
	int			s;
	int			mapx;
	int			mapy;
	char		**map;
	int			moves;
	int			won;
	int			lose;
	t_img		img;
	t_assets	set;
	t_player	pl;
	t_lst_exit	lst_exit;
	t_lst_colec	lst_colec;
	t_lst_enemy	lst_enemy;
	int			floor;
	int			walls;
	int			colect;
	int			player1;
	int			player2;
	int			player3;
	int			player4;
	int			end;
	int			enemy;
}				t_mlx;

#endif