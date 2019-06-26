/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:55:52 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/26 21:15:43 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_kek(t_point p)
{
	t_point	res;

	res.x = p.x * 100;
	res.y = p.y * 100;
	res.z = 0;
	return (res);
}

void    draw_map(t_fdf *fdf)
{
	int		i;
	t_point	p1;
	t_point p2;

	i = 0;
    while (i < fdf->width * fdf->height)
	{
		printf("%d   ", i);
		if (i % fdf->width < fdf->width - 1)
		{
			printf("1  ");
			// printf("FT_KEK x->%d, y->%d,    i = %d 1\n", fdf->point[i].x, fdf->point[i].y, i);
			p1 = ft_kek(fdf->point[i]);
			// printf("FT_KEK x->%d, y->%d,    i = %d 2\n", fdf->point[i + 1].x, fdf->point[i + 1].y, i + 1);
			p2 = ft_kek(fdf->point[i + 1]);
			draw_line(p1, p2, fdf->img, fdf);
		}
		if (i < (fdf->height - 1) * fdf->width)
		{
			printf("2   ");
			// printf("HERE %d %d x->%d y->%d\n", i, i+fdf->width, fdf->point[i + fdf->width].x, fdf->point[i + fdf->width].y);
			// printf("FT_KEK x->%d, y->%d,    i = %d 3\n", fdf->point[i].x, fdf->point[i].y, i);
			p1 = ft_kek(fdf->point[i]);
			printf("FT_KEK x->%d, y->%d,    i = %d 4\n", fdf->point[i + fdf->width].x, fdf->point[i + fdf->width].y, i + fdf->width);
			p2 = ft_kek(fdf->point[i + fdf->width]);
			printf("x0->%d, y0->%d x1->%d y1->%d\n", p1.x, p1.y, p2.x, p2.y);
			draw_line(p1, p2, fdf->img, fdf);
		}
		printf("\n");
		i++;
	}
}
