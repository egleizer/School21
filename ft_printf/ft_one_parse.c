/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:36:21 by phassan           #+#    #+#             */
/*   Updated: 2020/12/04 16:36:50 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_params		*element_init(void)
{
	t_params	*element;

	if (!(element = (t_params *)malloc(sizeof(t_params))))
		return (0);
	element->flag = "\0";
	element->width = 0;
	element->precision = "\0";
	element->length = 0;
	element->type = '0';
	element->tot_len = 0;
	element->el_len = 0;
	element->star_1 = 0;
	element->star_2 = 0;
	return (element);
}

void			second_star_parse(t_params *element)
{
	if (element->length < 0)
	{
		element->precision = "\0";
		element->length = 0;
		element->star_2 = 1;
	}
}

char			*first_star_parse(char *line, va_list list, t_params *element)
{
	if (ft_isdigit(*line))
	{
		element->width = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	else if (*line == '*')
	{
		element->width = va_arg(list, int);
		if (element->width < 0)
		{
			if (element->width < 0)
			{
				element->flag = "-\0";
				element->width = -1 * element->width;
				element->star_1 = 1;
			}
		}
		line++;
	}
	return (line);
}

char			*second_parse(char *line, va_list list, t_params *element)
{
	if (*line == '.')
	{
		element->precision = ".\0";
		line++;
		if (ft_isdigit(*line))
		{
			element->length = ft_atoi(line);
			while (ft_isdigit(*line))
				line++;
		}
		else if (*line == '*')
		{
			element->length = va_arg(list, int);
			second_star_parse(element);
			line++;
		}
	}
	element->type = *(char *)line++;
	element->tot_len = one_var_print(element, list);
	free(element);
	return (line);
}

char			*percent_parse(char *line, va_list list)
{
	t_params	*element;
	char		flag;

	if (!(element = element_init()))
		return (0);
	if ((*line == '0' && *(line + 1) != '.') || *line == '-')
	{
		flag = *line++;
		element->flag = &flag;
		if (flag == '0')
		{
			while (*line == '0' || *line == '-')
				flag = *line++;
		}
	}
	while (*line == '0' || *line == '-')
		line++;
	line = first_star_parse(line, list, element);
	return (second_parse(line, list, element));
}
