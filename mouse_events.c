/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:31:57 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/20 13:33:55 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		mousepress(int but, int x, int y, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)tmp;
	if (but == 53)
		exit(0);
	else if (but == 4)
		fdf->scale += 1;
	else if (but == 5)
		fdf->scale -= 1;
	else if (but == 1)
	{
		fdf->flags = 1;
		fdf->mouse.x = x;
		fdf->mouse.y = y;
	}
	else if (but == 2)
	{
		fdf->flags = 2;
		fdf->mouse.x = x;
		fdf->mouse.y = y;
	}
	draw_map(fdf);
	return (0);
}

int		mousemove(int x, int y, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)tmp;
	if (fdf->flags == 1)
	{
		fdf->angle.y -= (fdf->mouse.x - x) / 10;
		fdf->angle.x -= (fdf->mouse.y - y) / 10;
	}
	if (fdf->flags == 2)
	{
		fdf->offset_x += x - fdf->mouse.x;
		fdf->offset_y += y - fdf->mouse.y;
	}
	fdf->mouse.x = x;
	fdf->mouse.y = y;
	draw_map(fdf);
	return (0);
}

int		mouserelease(int but, int x, int y, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)tmp;
	if (but == 1 || but == 2)
		fdf->flags = 0;
	x = 0;
	y = 0;
	return (0);
}
