/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:53:56 by mplutarc          #+#    #+#             */
/*   Updated: 2019/06/19 15:20:38 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     valid(int ac, char **av)
{
	char    **line;
	char	**mapi;
    int     fd;
	int		i;
	size_t	size;

    fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		mapi = ft_strsplit(line, ' ');
		size = ft_count_words(line, ' ');
		while (mapi[i] != '\0')
		{
			
		}
	}
}
