/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:27:16 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/09 21:10:13 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keypress(int but, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)tmp;
	if (but == 53)
		exit(0);
	else if (but == 124)
		fdf->offset_x += 30;
	else if (but == 123)
		fdf->offset_x -= 30;
	else if (but == 125)
		fdf->offset_y += 30;
	else if (but == 126)
		fdf->offset_y -= 30;
	else if (but == 69)
		fdf->scale += 10;
	else if (but == 78)
		fdf->scale -= 10;
	draw_map(fdf);
	return (0);
}

int		mousepress(int but, int x, int y, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)tmp;
	if (but == 53)
		exit(0);
	else if (but == 4)
		fdf->angle += 1;
	else if (but == 5)
		fdf->angle -= 1;
	else if (but == 1)
	{
		fdf->offset_x = x;
		fdf->offset_y = y;
	}
	draw_map(fdf);
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}
