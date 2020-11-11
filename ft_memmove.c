/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:21:00 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/11 09:33:08 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *source;

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
