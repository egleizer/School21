#include "get_next_line.h"
#include <stdio.h>

int no_return(char *line)
{
	int index = 0;

	if (!line)
		return (0);
	while(line[index])
	{
		if (line[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

int ft_strlen(char *line)
{
	int s = 0;

	if (!line)
		return (0);
	while(line[s])
		s++;
	return(s);
}

void					*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*source;

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


char					*ft_strjoin(char *s1, char *s2, int buf_len)
{
	char				*pointer;
	size_t				s1_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	if (!(pointer = (char *)malloc(s1_len + buf_len + 1)))
		return (0);
	ft_memmove(pointer, s1, s1_len);
	ft_memmove(pointer + s1_len, s2, buf_len);
	pointer[s1_len + buf_len] = 0;
	free(s1);
	return (pointer);
}


char	*retrieve_line(char *whole_line)
{
	int index = 0;
	char	*ans_line;
	int len = 0;

	while (whole_line[len] && whole_line[len] != '\n')
		len++;
	if (!(ans_line = (char *)malloc(len + 1)))
		return (0);
	while (index < len)
	{
		ans_line[index] = whole_line[index];
		index++;
	}
	ans_line[index] = 0;
	return (ans_line);
}

char *retrieve_remains(char *line)
{
	int index = 0;
	char	*ans_line;
	int len = 0;

	while (line[len] && line[len] != '\n')
		len++;
	while (line[len + index])
		index++;
	if (!(ans_line = (char *)malloc(index + 1)))
		return (0);
	index = 0;
	while (line[len + index])
	{
		ans_line[index] = line[len + index];
		index++;
	}
	ans_line[index] = 0;
	free(line);
	return (ans_line);
}


int	 get_next_line(char **line)
{
	char *buffer;
	static char *whole_line;
	int buff_size = 128;

	if (!line || !(buffer= malloc(129)))
		return (-1);
	while (!no_return(whole_line) && buff_size != 0)
	{
		if ((buff_size = read(0, buffer, 128)) == -1)
			return (-1);
		if ((whole_line = ft_strjoin(whole_line, buffer, buff_size)) == 0)
			return (-1);
	}
	free(buffer);
	*line = retrieve_line(whole_line);
	if (buff_size == 0)
	{
		free(whole_line);
		whole_line = 0;
		return (0);
	}
	whole_line = retrieve_remains(whole_line);
	return(0);
}

int		main(void)
{
	int		ret_value;
	char	*line;

	line = NULL;
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(&line);
		printf("%d |>>| %s\n", ret_value, line);
	}
	return (0);
}