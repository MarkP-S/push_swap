/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:37:20 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/01 14:44:33 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	char		ch;

	i = n;
	if (i < 0)
	{
		write(fd, "-", 1);
		i *= -1;
	}
	if (i <= 9)
	{
		ch = i + '0';
		write(fd, &ch, sizeof(ch));
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}

/*
int main(void){

ft_putnbr_fd(-12444, 1);   
 
}
*/
