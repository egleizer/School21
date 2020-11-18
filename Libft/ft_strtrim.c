/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:22:10 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:33:00 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int		index;

	index = 0;
	while (set[index] != 0 && set[index] != c)
		index++;
	if (set[index] == c)
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*pointer;
	int		new_len;
	int		extra_len;
	int		index;

	new_len = 0;
	extra_len = 0;
	index = 0;
	while (s1[extra_len] && in_set(s1[extra_len], set))
		extra_len++;
	new_len = ft_strlen(s1) - 1;
	while (new_len >= 0 && in_set(s1[new_len], set))
		new_len--;
	new_len = new_len + 1 - extra_len;
	if (new_len <= 0)
		new_len = 0;
	if (!(pointer = (char *)malloc(new_len + 1)))
		return (0);
	while (index < new_len)
	{
		pointer[index] = s1[extra_len + index];
		index++;
	}
	pointer[index] = 0;
	return (pointer);
}
