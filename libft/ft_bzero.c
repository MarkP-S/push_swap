/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:01:50 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/23 01:23:55 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0)
	{
		*(temp) = 0;
		temp++;
		n--;
	}
}
/*
#include <stdio.h>

int main(void)
{
    char str[10];
    char *result = ft_memset(str, 'A', 5);
    result[5] = '\n';
    
    printf("result: %s", result);

    ft_bzero(result, 5);
    printf("Result after bzero: %s", result);
}
	*/