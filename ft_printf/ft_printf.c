/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:34:29 by phassan           #+#    #+#             */
/*   Updated: 2020/12/04 14:34:35 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_printf(const char *line, ...)
{
	va_list	list;
	char	*char_line;
	int		len;

	char_line = (char *)line;
	va_start(list, line);
	len = 0;
	while (*char_line)
	{
		if (*char_line == '%' && *(char_line + 1) != 0)
			char_line = percent_parse(++char_line, list);
		else
		{
			total_length(1);
			write(1, char_line++, 1);
		}
	}
	len = total_length(0);
	total_length(-1 * len);
	va_end(list);
	return (len);
}
