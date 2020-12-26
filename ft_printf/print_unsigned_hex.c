/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:30:05 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/12/07 13:30:07 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void				print_un_hex(unsigned int n, int len, t_params *element)
{
	int				remainder;
	static	int		tot_len;

	if (n < 16)
	{
		if (tot_len++ < len)
			print_hex_x_x(element, n);
	}
	else
	{
		remainder = n % 16;
		n = n / 16;
		print_un_hex(n, len, element);
		if (tot_len++ < len)
			print_hex_x_x(element, remainder);
	}
	if (tot_len == len)
		tot_len = 0;
}

void				print_un_hex_int_dash(t_params *element,
						int variable, int length)
{
	int				extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (*element->precision == '.')
	{
		print_zeros(element->length - element->el_len);
		if (*element->precision == '.' && element->length == 0
						&& element->width != 0 && variable == 0)
			print_empty(1);
		else if (!(*element->precision == '.'
						&& element->length == 0 && variable == 0))
			print_un_hex(variable, length, element);
		print_empty(element->width - extra_right);
	}
	else
	{
		print_un_hex(variable, length, element);
		if (element->width > length)
			print_empty(element->width - length);
	}
}

void				print_un_hex_int_zero(t_params *element,
						int variable, int length)
{
	int				extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (*element->precision == '.')
	{
		print_empty(element->width - extra_right);
		print_zeros(element->length - element->el_len);
		if (element->length == 0 && element->width != 0 && variable == 0)
			print_empty(1);
		if (!(*element->precision == '.'
						&& element->length == 0 && variable == 0))
			print_un_hex(variable, length, element);
	}
	else
	{
		if (element->width > length)
			print_zeros(element->width - length);
		print_un_hex(variable, length, element);
	}
}

void				print_un_hex_int_nothing(t_params *element,
						int variable, int length)
{
	int				extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (*element->precision == '.')
	{
		print_empty(element->width - extra_right);
		print_zeros(element->length - element->el_len);
		if (*element->precision == '.' && element->length == 0
			&& element->width != 0 && variable == 0)
			print_empty(1);
		else if (!(*element->precision == '.'
					&& element->length == 0 && variable == 0))
			print_un_hex(variable, length, element);
	}
	else
	{
		if (element->width > length)
			print_empty(element->width - length);
		print_un_hex(variable, length, element);
	}
}

int					print_un_hex_int(t_params *element, va_list list)
{
	unsigned int	variable;
	int				length;
	int				extra_right;

	variable = va_arg(list, unsigned int);
	if (variable < 0)
		variable = int_pow(2, 32) + variable;
	length = len_un_hex(variable);
	element->el_len = length;
	extra_right = (length > element->length) ? length : element->length;
	if (*element->flag == '-')
		print_un_hex_int_dash(element, variable, length);
	else if (*element->flag == '0')
		print_un_hex_int_zero(element, variable, length);
	else
		print_un_hex_int_nothing(element, variable, length);
	return (element->width > element->el_len
						? element->width : element->el_len);
}
