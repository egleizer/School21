/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:14:17 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:34:14 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	size_t	index;

	pointer = ft_strdup(s);
	if (!pointer)
		return (0);
	index = 0;
	while (s[index])
	{
		pointer[index] = (*f)(index, s[index]);
		index++;
	}
	return (pointer);
}
