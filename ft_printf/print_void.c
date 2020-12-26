/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:40:54 by phassan           #+#    #+#             */
/*   Updated: 2020/12/06 15:45:07 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void					print_void_flags(t_params *element,
						unsigned long int variable, int length)
{
	if (*element->precision == '.' &&
						element->length == 0 && element->width == 0)
	{
		total_length(2);
		write(1, "0", 1);
		write(1, "x", 1);
		return ;
	}
	if (*element->precision == '.' && element->length == 0)
	{
		print_empty(element->width - 2);
		total_length(2);
		write(1, "0", 1);
		write(1, "x", 1);
	}
	else
	{
		print_empty(element->width - element->el_len);
		print_hex(variable, length);
	}
}

int						print_void(t_params *element, va_list list)
{
	unsigned long int	variable;
	int					length;

	variable = va_arg(list, unsigned long int);
	length = len_hex(variable);
	element->el_len = length;
	if (*element->flag == '-')
	{
		if (*element->precision == '.' &&
						element->length == 0 && element->width == 0)
		{
			total_length(2);
			write(1, "0", 1);
			write(1, "x", 1);
			return (0);
		}
		else if (!(*element->precision == '.' && element->length == 0))
			print_hex(variable, length);
		if (!*element->precision)
			print_empty(element->width - element->el_len);
	}
	else
		print_void_flags(element, variable, length);
	return (element->width > element->el_len ?
						element->width : element->el_len);
}
