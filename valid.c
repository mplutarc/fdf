/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:53:56 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/24 19:35:13 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			valid(int ac, char **av)
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
		map = ft_lstnew(line, (ft_strlen(line) + 1) * sizeof(char));
		printf("ret - %d|   %s   |\n", ret, map->content);
		i++;
		set_coords(map, i);
	}
	return (1);
}

void		set_coords(t_list *map, int y)
{
	int		x;
	int		z;
	char	**line;
	t_point	point;

	x = 0;
	line = ft_strsplit(map->content, ' ');
	while(line[x] != '\0')
	{
		z = ft_atoi(line[x]);
		point = put_coords(x, y, z);
		printf("x = %d, y = %d, z = %d\n", point.x, point.y, point.z);
		x++;
	}
}
