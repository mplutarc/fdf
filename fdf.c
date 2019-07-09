/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:00:25 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/09 21:00:53 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_fdf		fdf;
	t_img		*img;

	if (!valid(ac, av, &fdf))
		return (0);
	img = (t_img *)ft_memalloc(sizeof(t_img));
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, "HUI");
	img->width = WIDTH;
	img->height = HEIGHT;
	img->img_ptr = mlx_new_image(fdf.mlx_ptr, img->width, img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp,
						&img->size_line, &img->endian);
	img->bpp /= 8;
	fdf.img = img;
	fdf.scale = 20;
	fdf.angle = 0;
	fdf.offset_x = 0;
	fdf.offset_y = 0;
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img->img_ptr, 0, 0);
	mlx_hook(fdf.win_ptr, 2, 0, keypress, &fdf);
	mlx_hook(fdf.win_ptr, 4, 0, mousepress, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, ft_close, &fdf);
	mlx_loop(fdf.mlx_ptr);
}

void		new_pxl(t_point p, t_img *img)
{
	if (p.x < 0 || p.y < 0 || p.x >= img->width || p.y >= img->height)
		return ;
	*(int *)(img->data_ptr + p.x * img->bpp + p.y *
				img->width * img->bpp) = 0xFFFFFF;
}

void		draw_line(t_point first, t_point last, t_img *img, t_fdf *fdf)
{
	t_bres	bres;

	bres.dx = abs(last.x - first.x);
	bres.dy = abs(last.y - first.y);
	bres.diry = ((last.y - first.y) == 0 ? 0 : (last.y - first.y) / bres.dy);
	bres.dirx = ((last.x - first.x) == 0 ? 0 : (last.x - first.x) / bres.dx);
	if (!(bresenham(bres, first, fdf, img)))
		return ;
}

int			bresenham(t_bres bres, t_point fir, t_fdf *fdf, t_img *img)
{
	int		f;
	int		x;
	int		y;

	f = 0;
	x = -1;
	y = 0;
	while (++x < bres.dx || y < bres.dy)
	{
		new_pxl(fir, img);
		f += bres.dy;
		while (2 * f >= bres.dx)
		{
			fir.y += bres.diry;
			y++;
			f -= bres.dx;
			new_pxl(fir, img);
			if (y > bres.dy)
				return (0);
		}
		if (x > bres.dx)
			return (0);
		fir.x += bres.dirx;
	}
	return (1);
}

t_point		put_coords(int x, int y, int z)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
