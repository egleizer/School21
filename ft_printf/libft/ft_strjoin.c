/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:32:06 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:32:19 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	l_1;
	size_t	l_2;

	l_1 = 0;
	l_2 = 0;
	pointer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!pointer)
		return (0);
	while (s1[l_1])
		pointer[l_2++] = s1[l_1++];
	l_1 = 0;
	while (s2[l_1])
		pointer[l_2++] = s2[l_1++];
	pointer[l_2] = 0;
	return (pointer);
}
