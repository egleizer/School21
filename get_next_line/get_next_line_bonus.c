/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:00:29 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/18 11:01:03 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int					no_return(char *line)
{
	int				index;

	index = 0;
	if (!line)
		return (0);
	while (line[index])
	{
		if (line[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*whole_line[10000];
	int				z;

	z = BUFFER_SIZE;
	if (fd < 0 || z <= 0 || !line || !(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!no_return(whole_line[fd]) && z != 0)
	{
		if ((z = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		if ((whole_line[fd] = ft_strjoin(whole_line[fd], buffer, z)) == 0)
			return (-1);
	}
	free(buffer);
	*line = retrieve_line(whole_line[fd]);
	if (z == 0)
	{
		free(whole_line[fd]);
		whole_line[fd] = 0;
		return (0);
	}
	if ((whole_line[fd] = retrieve_remains(whole_line[fd])) == 0)
		return (-1);
	return (1);
}
