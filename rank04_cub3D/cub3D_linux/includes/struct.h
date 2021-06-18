/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 09:42:10 by mdesfont          #+#    #+#             */
/*   Updated: 2020/08/10 18:06:16 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct	s_vector_dir
{
	double		x;
	double		y;
}				t_vector_dir;

typedef struct	s_pos_img
{
	int			x;
	int			y;
}				t_pos_img;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			s_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
	char		*name;
}				t_img;

typedef	struct	s_sprite
{
	t_img		texture;
	double		x;
	double		y;
}				t_sprite;

typedef struct	s_settings
{
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_s;
	t_img		text_no;
	t_img		text_so;
	t_img		text_we;
	t_img		text_ea;
	t_img		text_s;
	int			res_x;
	int			res_y;
	int			color_f;
	int			color_c;
	char		**map;
	char		player_dir;
}				t_settings;

typedef struct	s_game
{
	t_vector_dir	plane;
	t_vector_dir	player;
	t_vector_dir	player_direction;
	t_sprite		*sprite_list;
	int				sprite_nb;
}				t_game;

typedef struct	s_mlx
{
	int			save;
	char		*filename;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_settings	set;
	t_game		game;
}				t_mlx;

/*
** below, structs to bmp
** pragma must be deactivated, to avoid memory optimizations,
** because on the disk, there are no "gaps" between the data.
** Structures is contiguous in memory, because we are going to write it
** all at once.
** http://www.normalesup.org/~feuvrier/enseignement/2008/M2/site003.html
*/

# pragma pack(push, 1)

/*
** file header :
** type (here bm), file's size, reserve 4 bytes to 0, offset 54
** https://fulmanski.pl/zajecia/wdi/zajecia_20152016/bmp/dane/bmp
** _header_format.html
*/

typedef struct	s_bmfh
{
	char	fh_type[2];
	int		fh_size;
	int		fh_res;
	int		fh_offset_bits;

}				t_bmfh;

/*
** sizeof the header = sizeof BITMAPINFOHEADER
** widht of the image
** its height
** numbers of planes (always 1)
** bits per pixels
** compression, 0 if not compressed, compression never used in bmp
** total image size (aligments bytes included)
** scale factors for print size, x and y
** size of the pallet
** importants colors of the pallet
** !planes and count are on 2 octets, so not int
*/

typedef struct	s_bmih
{
	int		bi_size;
	int		bi_width;
	int		bi_height;
	char	bi_planes[2];
	char	bi_bit_count[2];
	int		bi_compression;
	int		bi_size_image;
	int		bix_pels_per_meter;
	int		biy_pels_per_meter;
	int		bi_clr_used;
	int		bi_clr_important;
}				t_bmih;
# pragma pack(pop)

#endif
