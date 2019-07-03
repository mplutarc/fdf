/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:23:04 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/03 17:07:26 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "math.h"
# include "libft/libft.h"
# include <stdio.h>
#include <mlx.h>
#include <stdio.h>
# define WIDTH 1800
# define HEIGHT 1200

// typedef struct		s_bahzd
// {
// 	void			*nesral;
//	void			*sral;
// 	char			********idinahui;
// }					t_bahzd;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_img
{
	void			*img_ptr;
	void			*data_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*img;
	t_point			*point;
	t_list			*field;
	int				*map;
	int				width;
	int				height;
	int				scale;
	int				offset_x;
	int				offset_y;
	int				angle;
}					t_fdf;

int					main();
void				draw_line(t_point first, t_point last, t_img *img, t_fdf *fdf);
void				new_pxl(t_point p, t_img *img);
t_point				put_coords(int x, int y, int z);
int					valid(int ac, char **av, t_fdf *fdf);
void				set_coords(t_fdf *fdf);
void				draw_map(t_fdf *fdf);
t_point				rotation_x(t_point p, int ngl);
t_point				rotation_y(t_point p, int ngl);
t_point				rotation_z(t_point p, int ngl);
t_point				ft_kek(t_point p, t_fdf *fdf);
int					keypress(int but, void *tmp);
int					mousepress(int but, int x, int y, void *tmp);
int  		       mousemove(int x, int y, void *tmp);

#endif
