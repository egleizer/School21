/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:24:50 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:25:05 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char char_c;
	char *char_s;

	char_c = (char)c;
	char_s = (char *)s;
	while (*char_s != 0)
	{
		if (*char_s == char_c)
			return (char_s);
		char_s++;
	}
	if (*char_s == char_c)
		return (char_s);
	return (0);
}
