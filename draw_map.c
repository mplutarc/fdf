/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:55:52 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/25 20:43:56 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_kek(t_point p)
{
	t_point	res;

	res.x = p.x * 10;
	res.y = p.y * 10;
	res.z = 0;
	return (res);
}

void    draw_map(t_fdf *fdf)
{
	int		i;
	t_point	p1;
	t_point p2;

	i = 0;
    while (i < fdf->width * fdf->height - 1)
	{
		// printf("%d\n", i);
		p1 = ft_kek(fdf->point[i]);
		p2 = ft_kek(fdf->point[i + 1]);
		draw_line(p1, p2, fdf->img);
		// draw_line(fdf->point[i], fdf->point[i + 1], *fdf->img);
		i++;
	}
}
