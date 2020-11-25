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

#include "get_next_line.h"

int				no_return(char *line)
{
	int			index;

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

int				get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*whole_line;
	char		*temp;
	int			z;

	z = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!no_return(whole_line) && z != 0)
	{
		if ((z = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		temp = ft_strjoin(whole_line, buffer, z);
		if (temp == 0)
			return (-1);
		free(whole_line);
		whole_line = temp;
	}
	free(buffer);
	*line = retrieve_line(whole_line);
	if (z == 0)
	{
		free(whole_line);
		whole_line = 0;
		return (0);
	}
	whole_line = retrieve_remains(whole_line);
	return (1);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	int a = 1;

	while ((a = get_next_line(fd, &line)))
	{
		printf("%s \n", line);
	//	free(line);
	}
	printf("Hello %s", line);
}

