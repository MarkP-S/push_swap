/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 00:23:08 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/24 23:37:59 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;
	size_t				i;

	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	i = -1;
	if (dest == src || n == 0)
		return (dest);
	else if (dest < src)
		while (++i < n)
			temp_dest[i] = temp_src[i];
	else if (dest > src)
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100] = "Learningisfun";
	char str2[100] = "Learningisfun";

	printf("Original string (str1) : %s\n", str1);
	printf("Original string (str2) : %s\n", str2);

	// Using memcpy on first copy
	memcpy(str1 + 8, str1, 10);
	printf("memcpy overlap  : %s\n", str1);

	// Using memmove on second independent copy
	ft_memmove(str2 + 8, str2, 10);
	printf("memmove overlap : %s\n", str2);

	return 0;
}
*/