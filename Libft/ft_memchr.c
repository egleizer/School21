/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:21:31 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:21:41 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char char_c;
	unsigned char *char_s;

	char_c = (unsigned char)c;
	char_s = (unsigned char *)s;
	while (n--)
	{
		if (*char_s == char_c)
			return (char_s);
		char_s++;
	}
	return (0);
}
