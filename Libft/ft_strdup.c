/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:31:24 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:31:31 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	char	*char_s;
	size_t	length;
	int		index;

	length = ft_strlen(s1) + 1;
	char_s = (char *)s1;
	pointer = (char *)malloc(length);
	index = 0;
	if (!pointer)
		return (0);
	while (char_s[index] != 0)
	{
		pointer[index] = char_s[index];
		index++;
	}
	pointer[index] = 0;
	return (pointer);
}
