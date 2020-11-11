/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:14:04 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/11 09:53:12 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *destination;
	unsigned char *source;

	if (dst == NULL && src == NULL)
		return (0);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (*destination == 0 && *source == 0)
		return (0);
	while (n--)
		*destination++ = *source++;
	return (dst);
}
