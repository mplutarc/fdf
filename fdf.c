/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:00:25 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/11 21:42:03 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int		main()
{
	t_fdf fdf;
	t_img img;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1800, 1200, "HUI");
	img.width = 800;
	img.height = 600;
	img.img_ptr = mlx_new_image(fdf.mlx_ptr, img.width, img.height);
	img.data_ptr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	draw_line(220, 500, 0, 2, img);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(fdf.mlx_ptr);
}

void	new_pxl(t_img img, int x, int y)
{
	*(int *)(img.data_ptr + x * img.bpp + y * img.width * img.bpp) = 0xFFFFFF;
}

void	draw_line(int x0, int y0, int x1, int y1, t_img img)
{
	int dx;
	int dy;
	int f;
	int fd;
	int sd;

	if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0)
		return ;
	img.x = x0;
	img.y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	f = ((abs(dx) > abs(dy)) ? dx : ((abs(dy) > abs(dx)) ? dy : 0)) / 2;
	fd = (dx >= dy) ? dx : dy;
	sd = (fd == dx) ? dy : dx;
	new_pxl(img, x0, y0);
	printf("BEFORE\n eto fd %d\n eto sd %d\n eto f %d\n dx = %d, dy = %d\n", fd, sd, f, dx, dy);
	int i = 0;
	while(img.x != x1 && img.y != y1)
	{
		printf("LOOP %d\n", i);
		i++;
		if (fd == dx)
		{
			img.x += dx / (abs(dx));
			img.y += dy / (abs(dy));
		}
		f = f - sd;
		printf("x = %d, y = %d\n", img.x, img.y);
		if (f <= 0)
		{
			img.y += dy / (abs(dy));
			img.x += dx / (abs(dx));
			f = f + fd;
		}
		new_pxl(img, img.x, img.y);
	}
	printf("AFTER\n eto fd %d\n eto sd %d\n eto f %d\n dx = %d, dy = %d\n", fd, sd, f, dx, dy);
}