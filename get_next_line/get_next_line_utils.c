/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:01:16 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/18 11:01:18 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(char *s)
{
	int				index;

	if (!s)
		return (0);
	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char				*ft_strjoin(char *s1, char *s2, int buf_len)
{
	char			*pointer;
	size_t			s1_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	if (!(pointer = (char *)malloc(s1_len + buf_len + 1)))
		return (0);
	ft_memmove(pointer, s1, s1_len);
	ft_memmove(pointer + s1_len, s2, buf_len);
	pointer[s1_len + buf_len] = 0;
	//free(s1);
	return (pointer);
}

void				*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	if (dest < source)
		while (len--)
			*dest++ = *source++;
	else
	{
		dest = dest + len - 1;
		source = source + len - 1;
		while (len--)
			*dest-- = *source--;
	}
	return (dst);
}

char				*retrieve_line(char *whole_line)
{
	int				index;
	int				len;
	char			*answer_line;

	len = 0;
	while (whole_line[len] && whole_line[len] != '\n')
		len++;
	if (!(answer_line = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	index = 0;
	while (whole_line[index] && whole_line[index] != '\n')
	{
		answer_line[index] = whole_line[index];
		index++;
	}
	answer_line[index] = '\0';
	return (answer_line);
}

char				*retrieve_remains(char *whole_line)
{
	int				index;
	int				len;
	char			*answer_line;

	len = 0;
	index = 0;
	while (whole_line[len] != '\n' && whole_line[len] != -1)
		len++;
	while (whole_line[len + index] != 0)
		index++;
	if (!(answer_line = (char *)malloc(sizeof(char) * index + 1)))
		return (0);
	index = 0;
	while (whole_line[len + index] != 0)
	{
		answer_line[index] = whole_line[len + index + 1];
		index++;
	}
	answer_line[index] = 0;
	return (answer_line);
}
