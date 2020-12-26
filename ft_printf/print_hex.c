/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:13:41 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/12/05 18:13:43 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			len_hex(unsigned long int n)
{
	int		len;

	len = 0;
	while ((n = n / 16) > 0)
		len++;
	return (len + 3);
}

void		hex_print(int n)
{
	char	new_n;

	total_length(1);
	if (n < 10)
	{
		new_n = n + '0';
		write(1, &new_n, 1);
	}
	else if (n == 10)
		write(1, "a", 1);
	else if (n == 11)
		write(1, "b", 1);
	else if (n == 12)
		write(1, "c", 1);
	else if (n == 13)
		write(1, "d", 1);
	else if (n == 14)
		write(1, "e", 1);
	else if (n == 15)
		write(1, "f", 1);
	else
		total_length(-1);
}

void		big_hex_print(int n)
{
	char	new_n;

	total_length(1);
	if (n < 10)
	{
		new_n = n + '0';
		write(1, &new_n, 1);
	}
	else if (n == 10)
		write(1, "A", 1);
	else if (n == 11)
		write(1, "B", 1);
	else if (n == 12)
		write(1, "C", 1);
	else if (n == 13)
		write(1, "D", 1);
	else if (n == 14)
		write(1, "E", 1);
	else if (n == 15)
		write(1, "F", 1);
	else
		total_length(-1);
}

void		print_hex(unsigned long int n, int len)
{
	unsigned long int		remainder;

	if (n < 16)
	{
		total_length(2);
		write(1, "0", 1);
		write(1, "x", 1);
		hex_print(n);
	}
	else
	{
		remainder = n % 16;
		n = n / 16;
		print_hex(n, len);
		hex_print(remainder);
	}
}

void		print_hex_x_x(t_params *element, int n)
{
	if (element->type == 'x')
		hex_print(n);
	else
		big_hex_print(n);
}
