/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugeniagleizer <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:41:12 by eugeniagl         #+#    #+#             */
/*   Updated: 2020/12/05 16:41:14 by eugeniagl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_printstr(char *str, int len)
{
	if (str == NULL)
		return ;
	while (len--)
	{
		write(1, str++, 1);
		total_length(1);
	}
}

int			print_string(t_params *element, va_list list)
{
	char	*variable;
	int		length;

	if (!(variable = va_arg(list, char*)))
		variable = "(null)\0";
	length = ft_strlen(variable);
	element->el_len = length;
	if (*element->precision == '.' && element->length < length)
		length = element->length;
	if (*element->flag)
	{
		ft_printstr(variable, length);
		print_empty(element->width - length);
	}
	else
	{
		print_empty(element->width - length);
		ft_printstr(variable, length);
	}
	return (element->width > element->el_len ? element->width
			: element->el_len);
}
