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
	char		*hay;
	char		*need;
	size_t		pointer;

	hay = (char *)haystack;
	need = (char *)needle;
	if (*need == 0)
		return (hay);
	while (*hay != 0 && len--)
	{
		if (*hay == *need)
		{
			pointer = 0;
			while (need[pointer] == hay[pointer] && pointer <= len)
				pointer++;
			if (need[pointer] == 0)
				return (hay);
		}
		hay++;
	}
	return (0);
}
