#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int result;
int width;
int dot;

void ft_putchar(char c)
{
	write(1, &c, 1);
	result++;
}

void ft_putstr(char *str, int len)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar(*str);
		str++;
		len--;
	}
}

int ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

char *ft_atoi(unsigned long nbr, int base)
{
	unsigned long temp = nbr;
	int len = 0;
	char *str;

	while (temp > 0)
	{
		temp /= base;
		len++;
	}
	str = (char *)malloc(len + 1);
	str[len] = 0;
	while (len > 0)
	{
		str[len-1] = nbr % base;
		if (nbr % base > 9)
			str[len-1] += 'a' - 10;
		else
			str[len-1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}

void ft_printf_x(unsigned long nbr)
{
	char *str;
	str = ft_itoa(nbr, 16);
	int len = ft_strlen(str);

	if (dot != -1 && dot > len)
		len = dot;
	while (width > len)
	{
		ft_putchar(' ');
		width--;
	}
	while (len > ft_strlen(str))
	{
		ft_putchar('0');
		len--;
	}
	ft_putstr(str, ft_strlen(str));
	free(str);
}


void ft_printf_d(int d)
{
	char *str;
	int minus = 0;
	if (d < 0)
	{
		minus = 1;
		d = -1 * d;
	}
	str = ft_itoa(nbr, 10);
	int len = ft_strlen(str);


	if (dot != -1 && dot > len)
		len = dot;
	if (minus == -1 && width > 0)
		width--;
	while (width > len)
	{
		ft_putchar(' ');
		width--;
	}
	if (minus == 1)
	{
		ft_putchar('-');
	}
	while (len > ft_strlen(str))
	{
		ft_putchar('0');
		len--;
	}
	ft_putstr(str, ft_strlen(str));
	free(str);
}

void ft_printf_s(char *str)
{
	int len = ft_strlen(str);

	if (dot != -1 && dot < len)
		len = dot;
	while (width > len)
	{
		ft_putchar(' ');
		width--;
	}
	ft_putstr(str, len);
	free(str);
}

int ft_printf(const char *str, ...)
{

	result = 0;
	int index = 0;
	va_list l;

	va_start(l, str);
	while (str[index])
	{
		if (str[index] == '%') {
			index++;
			width = 0;
			dot = -1;
			while (str[index] >= '0' && str[index] <= '9')
			{
				width = width * 10 + (str[index] - '0');
				index++;
			}
			if (str[index] == '.')
			{
				dot = 0;
				index++;
				while (str[index] >= '0' && str[index] <= '9')
				{
					dot = dot * 10 + (str[index] - '0');
					index++;
				}
			}
			if (str[index] == 's')
				ft_printf_s(va_arg(l, char *));
			else if (str[index] == 'x')
				ft_printf_x(va_arg(l, unsigned int));
			else if (str[index] == 'd')
				ft_printf_d(va_arg(l, int));
			else
				ft_putchar(str[index]);
		}
		else
			ft_putchar(str[i]);
		index++;
	}
	va_end(l);
	return(result);
}