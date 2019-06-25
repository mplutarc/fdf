/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:53:56 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/25 17:47:12 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			valid(int ac, char **av, t_fdf *fdf)
{
	char	*line;
	t_list	*map;
	int		fd;
	size_t	size;
	int		ret;
	int		i;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
	get_next_line(fd, &line);
	size = ft_count_words(line, ' ');
	printf("size = %zu\n", size);
	map = ft_lstnew(line, (ft_strlen(line) + 1) * sizeof(char));
	printf("map content = %s\n", map->content);
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(size == ft_count_words(line, ' ')))
			return (0);
		ft_lstadd(&map, ft_lstnew(line, (ft_strlen(line) + 1) * sizeof(char)));
		printf("ret = %d|   %s   |\n", ret, map->content);
		i++;
	}
	set_coords(map, fdf);
	return (1);
}

void		set_coords(t_list *map, t_fdf *fdf)
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
	head = map;
	while (map)
	{
		p += ft_count_words(map->content, ' ') + 1;
		map = map->next;
	}
	printf("p = %zu\n", p);
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
}
