/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_prints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:17:29 by phassan           #+#    #+#             */
/*   Updated: 2020/12/06 15:18:11 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void			print_empty(int len)
{
	if (len <= 0)
		return ;
	while (len--)
	{
		total_length(1);
		write(1, &" ", 1);
	}
}

void			print_zeros(int len)
{
	if (len <= 0)
		return ;
	while (len--)
	{
		total_length(1);
		write(1, &"0", 1);
	}
}

int				total_length(int len)
{
	static int	total_length;

	total_length = total_length + len;
	return (total_length);
}

int				len_un_hex(unsigned int n)
{
	int			len;

	len = 0;
	while ((n = n / 16) > 0)
		len++;
	return (len + 1);
}
