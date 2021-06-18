/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:05:36 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 13:57:01 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** bmp file header
*/

void	set_bmfh(t_bmfh *bmfh, t_mlx *mlx)
{
	bmfh->fh_type[0] = 'B';
	bmfh->fh_type[1] = 'M';
	bmfh->fh_size = 54 + 4 * mlx->set.res_x * mlx->set.res_y;
	bmfh->fh_res = 0;
	bmfh->fh_offset_bits = 54;
}

/*
** bmp infotmation header
*/

void	set_bmif(t_bmih *bmih, t_mlx *mlx)
{
	bmih->bi_size = 40;
	bmih->bi_width = mlx->set.res_x;
	bmih->bi_height = -mlx->set.res_y;
	bmih->bi_planes[0] = 1;
	bmih->bi_planes[1] = 0;
	bmih->bi_bit_count[0] = 32;
	bmih->bi_bit_count[1] = 0;
	bmih->bi_compression = 0;
	bmih->bi_size_image = 4 * mlx->set.res_x * mlx->set.res_y;
	bmih->bix_pels_per_meter = 0;
	bmih->biy_pels_per_meter = 0;
	bmih->bi_clr_used = 0;
	bmih->bi_clr_important = 0;
}

/*
** creates the file "screen.bmp"
** writes the contents from the struct bmfh to bmif and the pixel data stored
** in the struct t_mlx.img.data
** pargma command enables to count exactly same lenghth of the struct's memory
** like sizeof(bmfh)
*/

void	save_bmp(t_mlx *mlx)
{
	int		fd;
	t_bmfh	bmfh;
	t_bmih	bmih;

	run_game(mlx);
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0700)) < 0)
		close_error(mlx, ERR_BMPO, NULL, NULL);
	set_bmfh(&bmfh, mlx);
	set_bmif(&bmih, mlx);
	write(fd, &bmfh, sizeof(bmfh));
	write(fd, &bmih, sizeof(bmih));
	write(fd, mlx->img.data, bmih.bi_size_image);
	if (close(fd) == -1)
		close_error(mlx, ERR_BMPC, NULL, NULL);
	close_window(mlx, 1);
}
