/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 23:47:25 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/23 00:59:25 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*(temp) = (unsigned char) c;
		temp++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

int main(void) {

char str[10];
char *result = ft_memset(str, 'A', 5);
result[5] = '\n';

printf("result: %s", result);
}
*/