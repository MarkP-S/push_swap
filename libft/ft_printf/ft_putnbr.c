/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:37:20 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 17:21:06 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	ft_putnbr(int n)
{
	long long	i;
	int			count;

	count = 0;
	i = n;
	if (i < 0)
	{
		count += ft_putchar('-');
		i = -i;
	}
	if (i >= 10)
		count += ft_putnbr((int)(i / 10));
	count += ft_putchar((char)(i % 10 + '0'));
	return (count);
}
