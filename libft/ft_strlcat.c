/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:24:50 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/28 17:37:55 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				dest_size;
	size_t				src_size;

	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dest_size)
		return (size + src_size);
	i = 0;
	while (src[i] && (size > (dest_size + i + 1)))
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (dest_size + src_size);
}
/*
#include <stdio.h>

int main(void){
	//copy size-dest-1 bytes from src to end of dst
	//not including nul byte in src
	//initial src byte will overwrite nul at end of dst
	//end dst with nul unless exceding dest+size
	//return dst+src, but dst limited by size
	//if traverse size without finding nul, length is size
	//and dest is not nul-terminated

	char dest[] = "eeeee";
	char src[] = "hello";
	
	unsigned int result = ft_strlcat(dest, src, 10);
	
	printf("%d\n", result);
	printf("dest is: %s\n", dest);
	//printf("src is: %s\n", src);
}
*/