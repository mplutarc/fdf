/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:53:56 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/26 17:40:39 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			valid(int ac, char **av, t_fdf *fdf)
{
	char	*line;
	int		fd;
	size_t	size;
	int		ret;
	int		i;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	size = ft_count_words(line, ' ');
	fdf->field = ft_lstnew(line, (ft_strlen(line) + 1) * sizeof(char));
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(size == ft_count_words(line, ' ')))
			return (0);
		ft_lstadd(&fdf->field, ft_lstnew(line,
					(ft_strlen(line) + 1) * sizeof(char)));
		printf("ret = %d|   %s   |\n", ret, fdf->field->content);
		i++;
	}
	set_coords(fdf);
	return (1);
}

void		set_coords(t_fdf *fdf)
{
	int		x;
	int		z;
	int		y;
	char	**line;
	t_point	*point;
	t_list	*head;
	size_t	p;

	x = 0;
	p = 0;
	head = fdf->field;
	printf("I HAVE AUTISM\n");
	while (fdf->field)
	{
		p += ft_count_words(fdf->field->content, ' ') + 1;
		fdf->field = fdf->field->next;
	}
	point = ft_memalloc(sizeof(int) * p);
	p = 0;
	y = 0;
	while (head)
	{
		line = ft_strsplit(head->content, ' ');
		x = 0;
		while (line[x] != '\0')
		{
			z = ft_atoi(line[x]);
			point[p] = put_coords(x, y, z);
			x++;
			p++;
		}
		y++;
		head = head->next;
	}
	fdf->point = point;
	fdf->width = x;
	fdf->height = y;
	printf("height = %d, width = %d\n", fdf->height, fdf->width);
}
