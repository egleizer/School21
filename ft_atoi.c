/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:27:56 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/06 16:28:09 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		minus;
	int		result;

	s = (char *)str;
	result = 0;
	minus = 1;
	while (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f' || *s == '\r'
			|| *s == ' ')
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		minus = -1;
		s++;
	}
	while (*s > 47 && *s < 58)
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (minus * result);
}
