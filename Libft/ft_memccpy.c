/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:14:51 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/10 18:14:19 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	unsigned char	stopper;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	stopper = (unsigned char)c;
	while (n--)
	{
		*destination = *source;
		destination++;
		if (*source == stopper)
			return (destination);
		source++;
	}
	return (0);
}
