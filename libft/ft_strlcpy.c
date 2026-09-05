/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:21:10 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/24 22:53:48 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				j;

	j = 0;
	while (src[j])
		j++;
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

/*
#include <stdio.h>

int main(void)
{    
    char dest[] = "things"; 
    char src[] = "Jestem";
    
    unsigned int result = ft_strlcpy(dest, src, 14); 
    //sample strings of 6, n okay, until 16 which gives stack smashing error

    printf("%d", result);
}
*/