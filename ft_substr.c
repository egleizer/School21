/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:31:47 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:31:54 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	char	*char_s;
	int		index;

	pointer = (char *)malloc(sizeof(*s) * len + 1);
	if (!pointer)
		return (0);
	char_s = (char *)s + start;
	index = 0;
	while (len--)
	{
		pointer[index] = char_s[index];
		index++;
	}
	pointer[index] = 0;
	return (pointer);
}
