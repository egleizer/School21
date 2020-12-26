/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:23:37 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:23:47 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned char	*char_s;
	size_t			str_len;

	char_s = (unsigned char *)s;
	str_len = 0;
	while (*char_s != 0)
	{
		str_len++;
		char_s++;
	}
	return (str_len);
}
