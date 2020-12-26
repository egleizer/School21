/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:13:20 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/12/05 22:13:24 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			print_int_flag_dot(t_params *element,
				int length, long int variable)
{
	int			extra_right;
	int			flag;

	flag = 0;
	extra_right = (length > element->length) ? length : element->length;
	if (*element->precision == '.' && element->length == 0
		&& (element->width == 0 || variable == 0))
		extra_right = 0;
	if (variable < 0 && extra_right != length)
		extra_right++;
	if (variable < 0 && flag++ == 0)
	{
		total_length(1);
		write(1, &"-", 1);
		variable = -1 * variable;
		length--;
	}
	print_zeros(element->length - length);
	if (!(*element->precision == '.'
									&& element->length == 0 && variable == 0))
		print_number(variable);
	if (flag == 1 && *element->precision == '.'
									&& element->width <= element->length + 1)
		extra_right++;
	print_empty(element->width - extra_right);
}

void			print_int_flag_zero_neg(t_params *element,
							int length, long int variable, int extra_right)
{
	if (*element->precision == '.' || element->length != 0)
	{
		if (*element->precision == '.' && element->width <= element->length + 1)
			print_empty(element->width - extra_right - 1);
		else
			print_empty(element->width - extra_right);
		total_length(1);
		write(1, &"-", 1);
		if (element->length > element->el_len - 1)
			print_zeros(element->length - element->el_len + 1);
		else
			print_zeros(extra_right - length);
		variable = -1 * variable;
		print_number(variable);
	}
	else
	{
		total_length(1);
		write(1, &"-", 1);
		print_zeros(element->width - length);
		variable = -1 * variable;
		print_number(variable);
	}
}

void			print_int_flag_zero(t_params *element,
									int length, long int variable)
{
	int			extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (variable < 0 && extra_right != length)
		extra_right++;
	if (variable < 0)
		print_int_flag_zero_neg(element, length, variable, extra_right);
	else if (element->length > 0 || *element->precision == '.')
	{
		print_empty(element->width - extra_right);
		print_zeros(extra_right - length);
		if (!(*element->precision == '.' && element->length == 0
								&& variable == 0))
			print_number(variable);
		else if (variable == 0 &&
								!(element->length == 0 && element->width == 0))
			print_empty(1);
	}
	else
	{
		print_zeros(element->width - length);
		if (!(*element->precision == '.' && element->length == 0))
			print_number(variable);
	}
}

void			print_int_no_flag(t_params *element,
									int length, long int variable)
{
	int			extra_right;

	extra_right = (length > element->length) ? length : element->length;
	if (*element->precision == '.' && element->length == 0
							&& (element->width == 0 || variable == 0))
		extra_right = 0;
	if (variable < 0 && extra_right != length)
		extra_right++;
	if (element->star_1 == 1)
		element->width = 0;
	if (variable < 0 && *element->precision == '.'
							&& element->width <= element->length + 1)
		print_empty(element->width - extra_right - 1);
	else
		print_empty(element->width - extra_right);
	if (variable < 0)
	{
		total_length(1);
		write(1, &"-", 1);
		variable = -1 * variable;
		length--;
	}
	print_zeros(element->length - length);
	if (!(*element->precision == '.' && element->length == 0 && variable == 0))
		print_number(variable);
}

int				print_int(t_params *element, va_list list)
{
	long int	variable;
	int			length;

	variable = va_arg(list, int);
	length = num_length(variable);
	element->el_len = length;
	if (!*element->flag)
	{
		print_int_no_flag(element, length, variable);
	}
	else if (*element->flag == '0')
		print_int_flag_zero(element, length, variable);
	else
		print_int_flag_dot(element, length, variable);
	return (element->width > element->el_len ?
							element->width : element->el_len);
}
