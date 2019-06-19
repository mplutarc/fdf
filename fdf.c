/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:00:25 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/18 19:16:14 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int			main(void)
{
	t_fdf		fdf;
	t_img		img;
	t_point		first;
	t_point		last;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1800, 1200, "HUI");
	img.width = 800;
	img.height = 600;
	img.img_ptr = mlx_new_image(fdf.mlx_ptr, img.width, img.height);
	img.data_ptr = mlx_get_data_addr(img.img_ptr, &img.bpp,
						&img.size_line, &img.endian);
	img.bpp /= 8;
	first = put_coords(700, 500);
	last = put_coords(100, 100);
	draw_line(first, last, img);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(fdf.mlx_ptr);
}

void		new_pxl(t_point p, t_img img)
{
	if (p.x < 0 || p.y < 0 || p.x > img.width || p.y > img.height)
		return ;
	*(int *)(img.data_ptr + p.x * img.bpp + p.y *
				img.width * img.bpp) = 0xFFFFFF;
}

void		draw_line(t_point first, t_point last, t_img img)
{
	int		dx;
	int		dy;
	int		f;
	int		diry;
	int		dirx;

	if (first.x < 0 || first.y < 0 || last.x < 0 || last.y < 0)
		return ;
	f = 0;
	dx = abs(last.x - first.x);
	dy = abs(last.y - first.y);
	diry = ((last.y - first.y) == 0 ? 0 : (last.y - first.y) / dy);
	dirx = ((last.x - first.x) == 0 ? 0 : (last.x - first.x) / dx);
	while ((first.x != last.x))
	{
		new_pxl(first, img);
		f += dy;
		while (2 * f >= dx)
		{
			first.y += diry;
			f -= dx;
			new_pxl(first, img);
		}
		first.x += dirx;
	}
}

t_point		put_coords(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}
