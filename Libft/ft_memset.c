/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:12:30 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:12:41 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	char_int;
	unsigned char	*pointer;

	char_int = (unsigned char)c;
	pointer = (unsigned char *)b;
	while (len--)
	{
		*pointer = char_int;
		pointer++;
	}
	return (b);
}
