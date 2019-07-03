/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:00:25 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/03 17:09:19 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_fdf		fdf;
	t_img		*img;

	if (!valid(ac, av, &fdf))
		return (0);
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
	fdf.scale = 20;
	fdf.angle = 0;
	fdf.offset_x = 0;
	fdf.offset_y = 0;
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img->img_ptr, 0, 0);
	mlx_hook(fdf.win_ptr, 2, 0, keypress, &fdf);
	mlx_hook(fdf.win_ptr, 4, 0, mousepress, &fdf);
	// mlx_hook(fdf.win_ptr, 6, 0, mousemove, &fdf);
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
	int		dx;
	int		dy;
	int		f;
	int		diry;
	int		dirx;
	int		x;
	int		y;

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
			if (y > dy)
				return ;
		}
		if (x > dx)
			return ;
		first.x += dirx;
		x++;
	}
}

t_point		put_coords(int x, int y, int z)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
