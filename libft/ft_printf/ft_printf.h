/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:09:56 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 20:32:03 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_putchar(int fd, char c);
int		ft_putstr(int fd, char *s);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int fd, int n);
int		ft_putunsigned(int fd, unsigned int n);
int		ft_puthex(int fd, unsigned long long n, char *base);
int		ft_putptr(int fd, void *ptr);
int		ft_printf_fd(int fd, const char *format, ...);

#endif