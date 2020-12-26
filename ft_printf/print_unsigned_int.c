/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:29:31 by phassan           #+#    #+#             */
/*   Updated: 2020/12/06 17:34:40 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

long int		int_pow(int base, int exp)
{
	long	int	result;

	result = 1;
	while (exp)
	{
		result = result * base;
		exp--;
	}
	return (result);
}

void			print_un_int_flag_zero(t_params *element, int length,
										long int variable)
{
	int			extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (*element->precision == '.')
	{
		if (!(*element->precision == '.' && element->width <= element->el_len
				&& element->length == 0 && variable != 0))
			print_empty(element->width - extra_right);
		print_zeros(element->length - length);
		if (!(*element->precision == '.'
							&& element->length == 0 && variable == 0))
			print_number(variable);
		else if (*element->precision == '.' && element->length == 0
				&& element->width != 0 && variable == 0)
			print_empty(1);
	}
	else
	{
		print_zeros(element->width - element->el_len);
		if (!(*element->precision == '.' && element->length == 0))
			print_number(variable);
	}
}

void			print_un_int_flag_min(t_params *element, int length,
				long int variable)
{
	int			extra_right;

	extra_right = (length > element->length) ? length : element->length;
	print_zeros(element->length - length);
	if (!(*element->precision == '.' && element->length == 0 && variable == 0))
		print_number(variable);
	else if (*element->precision == '.' && element->width != 0
				&& element->length == 0 && variable == 0)
		print_empty(1);
	print_empty(element->width - extra_right);
}

void			print_un_int_no_flag(t_params *element,
				int length, long int variable)
{
	int			extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (!(*element->precision == '.' && element->width <= element->el_len
			&& element->length == 0 && variable != 0))
		print_empty(element->width - extra_right);
	print_zeros(element->length - length);
	if (!(*element->precision == '.'
			&& element->length == 0 && variable == 0))
		print_number(variable);
	else if (!(element->length == 0 && variable == 0 && element->width == 0))
		print_empty(1);
}

int				print_un_int(t_params *element, va_list list)
{
	long int	variable;
	int			length;

	variable = va_arg(list, int);
	if (variable < 0)
		variable = int_pow(2, 32) + variable;
	length = num_length(variable);
	element->el_len = length;
	if (!*element->flag)
		print_un_int_no_flag(element, length, variable);
	else if (*element->flag == '0')
		print_un_int_flag_zero(element, length, variable);
	else
		print_un_int_flag_min(element, length, variable);
	return (0);
}
