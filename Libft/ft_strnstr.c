/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:26:58 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:27:12 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	pointer;
	size_t	index;

	if (!(needle_len = ft_strlen(needle)))
		return ((char *)haystack);
	if (ft_strlen(haystack) < needle_len || len < needle_len)
		return (NULL);
	index = 0;
	while (haystack[index] && index <= len - needle_len)
	{
		pointer = 0;
		while (needle[pointer] == haystack[index + pointer] && needle[pointer])
			pointer++;
		if (pointer == needle_len)
			return ((char *)haystack + index);
		index++;
	}
	return (0);
}
