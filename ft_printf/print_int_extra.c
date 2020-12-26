/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:38:44 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/12/21 00:38:51 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			num_length(long int n)
{
	int		l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		l++;
		n = -1 * n;
	}
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

void		print_digit(int n)
{
	char	char_n;

	char_n = n + '0';
	total_length(1);
	write(1, &char_n, 1);
}

void		print_number(long int n)
{
	int		remainder;

	if (n < 0)
	{
		total_length(1);
		write(1, &"-", 1);
		n = -1 * n;
	}
	if (n < 10)
		print_digit(n);
	else
	{
		remainder = n % 10;
		n = n / 10;
		print_number(n);
		print_digit(remainder);
	}
}
