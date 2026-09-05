/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:44:13 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 19:31:52 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	ft_putptr(int fd, void *ptr)
{
	if (!ptr)
		return (ft_putstr(fd, "(nil)"));
	return (ft_putstr(fd, "0x")
		+ ft_puthex(fd, (unsigned long long)ptr, "0123456789abcdef"));
}
