/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_var_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:44 by phassan           #+#    #+#             */
/*   Updated: 2020/12/04 18:09:49 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	one_var_print(t_params *element, va_list list)
{
	if (element->type == 'c' || element->type == '%')
		print_char(element, list);
	if (element->type == 's')
		print_string(element, list);
	if (element->type == 'p')
		print_void(element, list);
	if (element->type == 'd' || element->type == 'i')
		print_int(element, list);
	if (element->type == 'u')
		print_un_int(element, list);
	if (element->type == 'x' || element->type == 'X')
		print_un_hex_int(element, list);
	return (element->tot_len);
}
