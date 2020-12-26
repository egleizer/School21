/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:31:32 by phassan           #+#    #+#             */
/*   Updated: 2020/12/06 14:53:08 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		print_char_flag(t_params *element, char variable)
{
	if (*element->flag == '0' && element->type == '%')
	{
		print_zeros(element->width - 1);
		total_length(1);
		write(1, &variable, 1);
	}
	else if (*element->flag)
	{
		total_length(1);
		write(1, &variable, 1);
		print_empty(element->width - 1);
	}
	else
	{
		total_length(1);
		print_empty(element->width - 1);
		write(1, &variable, 1);
	}
}

int			print_char(t_params *element, va_list list)
{
	char	variable;
	int		answer;

	if (element->type == '%')
		variable = '%';
	else
		variable = (char)va_arg(list, int);
	print_char_flag(element, variable);
	element->el_len = 1;
	answer = element->width > 1 ? element->width : 1;
	element->tot_len = element->width > element->el_len
			? element->width : element->el_len;
	return (answer);
}
