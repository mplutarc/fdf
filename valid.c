/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:53:56 by mplutarc          #+#    #+#             */
/*   Updated: 2019/07/09 20:56:18 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			valid(int ac, char **av, t_fdf *fdf)
{
	char	*line;
	int		fd;
	size_t	size;
	int		ret;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	size = ft_count_words(line, ' ');
	fdf->field = ft_lstnew(line, (ft_strlen(line) + 1) * sizeof(char));
	free(line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(size == ft_count_words(line, ' ')))
		{
			return (0);
		}
		ft_lstadd(&fdf->field, ft_lstnew(line,
					(ft_strlen(line) + 1) * sizeof(char)));
		free(line);
	}
	set_coords(fdf);
	return (1);
}

void		set_coords(t_fdf *fdf)
{
	t_tmp	tmp;
	t_point	*point;
	t_list	*head;

	head = fdf->field;
	tmp.x = 0;
	tmp.p = 0;
	tmp.y = 0;
	setset_coords(head, fdf, &tmp, &point);
	fdf->point = point;
	fdf->width = tmp.x;
	fdf->height = tmp.y;
	ft_lstfree(fdf->field);
}

void		setset_coords(t_list *head, t_fdf *fdf, t_tmp *tmp, t_point **point)
{
	char	**line;

	while (head)
	{
		tmp->p += ft_count_words(fdf->field->content, ' ') + 1;
		head = head->next;
	}
	head = fdf->field;
	*point = (t_point *)ft_memalloc(sizeof(t_point) * tmp->p);
	tmp->p = 0;
	while (head)
	{
		line = ft_strsplit(head->content, ' ');
		tmp->x = 0;
		while (line[tmp->x] != '\0')
		{
			tmp->z = ft_atoi(line[tmp->x]);
			(*point)[tmp->p] = put_coords(tmp->x, tmp->y, tmp->z);
			tmp->x++;
			tmp->p++;
		}
		ft_free(line, ft_count_words(head->content, ' '));
		tmp->y++;
		head = head->next;
	}
}
