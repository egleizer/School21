/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:24:00 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:24:09 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t len;

	src_len = ft_strlen(src);
	if (dstsize == 0 || src == NULL)
		return (src_len);
	len = dstsize - 1;
	if (src_len < dstsize - 1)
		len = src_len;
	if (dstsize != 0)
	{
		ft_memcpy(dst, src, len);
		dst[len] = 0;
	}
	return (src_len);
}
