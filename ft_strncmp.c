/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:27:27 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:27:35 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- && *char_s1 && *char_s2)
	{
		if (*char_s1 != *char_s2)
			return (*char_s1 - *char_s2);
		char_s1++;
		char_s2++;
	}
	if (*char_s1 == 0 && *char_s2 != 0)
		return (-1 * (*char_s2));
	if (*char_s1 != 0 && *char_s2 == 0)
		return (*char_s1);
	return (0);
}
