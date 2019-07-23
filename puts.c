/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:22:04 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/20 17:55:09 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put(t_fdf *fdf)
{
	fdf->scale = 20;
	fdf->angle.x = 0;
	fdf->angle.y = 0;
	fdf->angle.z = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->flags = 0;
}
