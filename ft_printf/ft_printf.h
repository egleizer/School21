/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phassan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:35:23 by phassan           #+#    #+#             */
/*   Updated: 2020/12/04 14:35:27 by phassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_params
{
	char		*flag;
	int			width;
	char		*precision;
	int			length;
	char		type;
	int			tot_len;
	int			el_len;
	int			star_1;
	int			star_2;
}				t_params;

int				ft_printf(const char *line, ...);
char			*percent_parse(char *line, va_list list);
int				one_var_print(t_params *element, va_list list);
int				print_char(t_params *element, va_list list);
int				print_string(t_params *element, va_list list);
void			print_hex(unsigned long int n, int len);
int				print_int(t_params *element, va_list list);
int				len_hex(unsigned long int n);
void			print_empty(int len);
void			print_zeros(int len);
void			print_digit(int n);
void			print_number(long int n);
int				num_length(long int n);
void			hex_print(int n);
int				print_void(t_params *element, va_list list);
int				print_un_int(t_params *element, va_list list);
int				print_un_hex_int(t_params *element, va_list list);
long int		int_pow(int base, int exp);
int				total_length(int len);
void			big_hex_print(int n);
void			print_hex_x_x(t_params *element, int n);
int				len_un_hex(unsigned int n);

#endif
