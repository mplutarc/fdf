/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:00:25 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/26 21:17:31 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int			main(int ac, char **av)
{
	t_fdf		fdf;
	t_img		*img;

	if (!valid(ac, av, &fdf))
		return (0);
	// fdf = ft_memalloc(sizeof(fdf))
	img = ft_memalloc(sizeof(t_img));
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, "HUI");
	img->width = WIDTH;
	img->height = HEIGHT;
	img->img_ptr = mlx_new_image(fdf.mlx_ptr, img->width, img->height);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp,
						&img->size_line, &img->endian);
	img->bpp /= 8;
	fdf.img = img;
	draw_map(&fdf);
	// printf("%p %p %p\n", fdf.mlx_ptr, fdf.win_ptr, fdf.img->img_ptr);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img->img_ptr, 0, 0);
	mlx_loop(fdf.mlx_ptr);

}

void		new_pxl(t_point p, t_img *img)
{
	if (p.x < 0 || p.y < 0 || p.x > img->width || p.y > img->height)
		return ;
	*(int *)(img->data_ptr + p.x * img->bpp + p.y *
				img->width * img->bpp) = 0xFFFFFF;
}

void		draw_line(t_point first, t_point last, t_img *img, t_fdf *fdf)
{
	int		dx;
	int		dy;
	int		f;
	int		diry;
	int		dirx;
	int		x;
	int		y;

	// if (first.x < 0 || first.y < 0 || last.x < 0 || last.y < 0)
	// 	return ;
	// printf("%d %d %d %d\n", first.x, first.y, last.x, last.y);
	f = 0;
	x = 0;
	y = 0;
	dx = abs(last.x - first.x);
	dy = abs(last.y - first.y);
	diry = ((last.y - first.y) == 0 ? 0 : (last.y - first.y) / dy);
	dirx = ((last.x - first.x) == 0 ? 0 : (last.x - first.x) / dx);
	while (x < dx || y < dy)
	{
		new_pxl(first, img);
		f += dy;
		while (2 * f >= dx)
		{
			first.y += diry;
			y++;
			f -= dx;
			new_pxl(first, img);
			// printf("PRINTY %d %d %d %d\n", y, dy, last.y, first.y);
			if (y > dy)
				return ;
		}
		if (x > dx)
			return ;
		// printf("PRINTX %d\n", x);
		first.x += dirx;
		x++;
	}
	// printf("\n\n\nVYSHEL\n\n\n");
}

t_point		put_coords(int x, int y, int z)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
