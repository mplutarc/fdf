/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:55:52 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/03 18:25:25 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_kek(t_point p, t_fdf *fdf)
{
	t_point	res;

	res.x = p.x * fdf->scale + fdf->offset_x;
	res.y = p.y * fdf->scale + fdf->offset_y;
	res.z = p.z * fdf->scale;
	res = rotation_x(res, fdf->angle);
	return (res);
}

t_point	rotation_x(t_point p, int ngl)
{
	float angle = ngl * 0.0175f;
	t_point res;

	res.x = p.x;
	res.y = p.y * cos(angle) + p.z * sin(angle);
	res.z = (p.y * -1) * sin(angle) + p.z * cos(angle);
	return(res);
}

t_point	rotation_y(t_point p, int ngl)
{
	float angle = ngl * 0.0175f;
	t_point res;

	res.x = p.x * cos(angle) + p.z * sin(angle);
	res.y = p.y;
	res.z = (p.x * -1) * sin(angle) + p.z * cos(angle);
	return(res);
}

t_point	rotation_z(t_point p, int ngl)
{
	float angle = ngl * 0.0175f;
	t_point res;

	res.x = p.x * cos(angle) - p.y * sin(angle);
	res.y = p.x * sin(angle) + p.y * cos(angle);
	res.z = p.z;
	return(res);
}

void    draw_map(t_fdf *fdf)
{
	ft_bzero(fdf->img->data_ptr, sizeof(int) * WIDTH * HEIGHT);
	int		i;
	t_point	p1;
	t_point p2;

	i = 0;
    while (i < fdf->width * fdf->height)
	{
		if (i % fdf->width < fdf->width - 1)
		{
			p1 = ft_kek(fdf->point[i], fdf);
			p2 = ft_kek(fdf->point[i + 1], fdf);
			draw_line(p1, p2, fdf->img, fdf);
		}
		if (i < (fdf->height - 1) * fdf->width)
		{
			
			p1 = ft_kek(fdf->point[i], fdf);
			p2 = ft_kek(fdf->point[i + fdf->width], fdf);
			draw_line(p1, p2, fdf->img, fdf);
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
}
