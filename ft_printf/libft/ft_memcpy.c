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
	unsigned char		*destination;
	const unsigned char *source;

	if (dst == NULL && src == NULL)
		return (NULL);
	destination = dst;
	source = src;
	while (n--)
		*destination++ = *source++;
	return (dst);
}
