/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:04:22 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 19:29:39 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	ft_puthex(int fd, unsigned long long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(fd, n / 16, base);
	count += ft_putchar(fd, base[n % 16]);
	return (count);
}
