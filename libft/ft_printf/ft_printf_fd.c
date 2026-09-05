/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:03:44 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 20:32:24 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"


static int	ft_is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	ft_formats(int fd, char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(fd, va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(fd, va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(fd, va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunsigned(fd, va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(fd, va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(fd, va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(fd, va_arg(*args, void *)));
	else if (c == '%')
		return (ft_putchar(fd, '%'));
	return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_is_conversion(format[i + 1]))
		{
			count += ft_formats(fd, format[i + 1], &args);
			i++;
		}
		else
			count += ft_putchar(fd, format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
