/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:23:04 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/11 20:54:59 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "math.h"

// typedef struct		s_bahzd
// {
// 	void			*nesral;
//	void			*sral;
// 	char			********idinahui;
// }					t_bahzd;

typedef struct		s_img
{
	void			*img_ptr;
	void			*data_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				x;
	int				y;
}					t_img;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*img;
}					t_fdf;

int					main();
void	draw_line(int x0, int y0, int x1, int y1, t_img img);
void	new_pxl(t_img img, int x, int y);

#endif
