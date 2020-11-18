/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:42:24 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/10 18:21:45 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**big_allocate(char const *s, char c)
{
	char		**pointer;
	int			words;
	int			index;

	words = 0;
	index = 0;
	while (s[index] != 0)
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == 0))
			words++;
		index++;
	}
	if (!(pointer = (char **)malloc(sizeof(char *) * (words + 1))))
		return (0);
	return (pointer);
}

static	int		next_str_len(const char *s, int index, char c)
{
	int			len;

	len = 0;
	while (s[index + len] != c && s[index + len] != 0)
		len++;
	return (len);
}

static	char	*allocate_till_c(const char *s, int str_ind, char c)
{
	int			len;
	char		*p;
	int			in;

	len = next_str_len(s, str_ind, c);
	if (!(p = (char *)malloc(len + 1)))
		return (0);
	in = 0;
	while (in < len)
	{
		p[in] = s[str_ind + in];
		in++;
	}
	p[in] = 0;
	return (p);
}

static	void	free_space(char **point, int index)
{
	if (index == 0)
		return ;
	while (index--)
		free(point[index]);
	free(point);
}

char			**ft_split(char const *s, char c)
{
	char		**pointer;
	int			index;
	int			str_ind;

	index = 0;
	str_ind = 0;
	if (!(pointer = (char **)big_allocate(s, c)))
		return (0);
	while (s[str_ind] != 0)
	{
		while (s[str_ind] == c)
			str_ind++;
		if (s[str_ind] == 0)
			break ;
		if (!(pointer[index] = allocate_till_c(s, str_ind, c)))
		{
			free_space(pointer, index);
			return (0);
		}
		index++;
		str_ind = str_ind + next_str_len(s, str_ind, c);
	}
	pointer[index] = 0;
	return (pointer);
}
