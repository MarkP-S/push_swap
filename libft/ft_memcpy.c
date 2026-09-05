/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 22:20:56 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/24 21:48:48 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(temp_dest++) = *(temp_src++);
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main() {

    // int a = 20;
    // int b = 10;
    
    // printf("Value of b before calling memcpy: %d\n", b);

    // // Use memcpy to copy the value of 'a' into 'b'
    // ft_memcpy(&b, &a, sizeof(int)); 

    // printf("Value of b after calling memcpy: %d\n", b);

    char str1[100] = "Learningisfun";
    char str2[100] = "Learningisfun";

    printf("Original string (str1) : %s\n", str1);
    printf("Original string (str2) : %s\n", str2);

    // Using memcpy on first copy
    ft_memcpy(str1 + 8, str1, 10);
    printf("memcpy overlap  : %s\n", str1);

    // Using memmove on second independent copy
    memmove(str2 + 8, str2, 10);
    printf("memmove overlap : %s\n", str2);

    return 0;
}
*/
