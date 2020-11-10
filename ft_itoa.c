/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:26:44 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/11/10 18:19:17 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		num_len(int n)
{
	int			l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -1 * n;
	}
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static	void	fill_in(int n, char *p, int len)
{
	if (len == 0)
		return ;
	if (n < 0)
	{
		*p++ = '-';
		n = (-1) * n;
	}
	fill_in(n / 10, p, len - 1);
	p[len - 1] = (n - (n / 10) * 10) + '0';
}

char			*ft_itoa(int n)
{
	int			len;
	char		*pointer;

	if (n == -2147483648LL)
	{
		pointer = (char *)malloc(sizeof(char) * 12);
		pointer[0] = '-';
		pointer[1] = '2';
		n = 147483648;
		fill_in(n, pointer + 2, num_len(n));
		return (pointer);
	}
	len = num_len(n);
	pointer = (char *)malloc(sizeof(char) * len + 1);
	fill_in(n, pointer, len);
	return (pointer);
}
