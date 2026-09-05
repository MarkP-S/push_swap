/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 01:51:33 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/27 19:58:54 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	i = 0;
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (i < (nmemb * size))
		temp[i++] = 0;
	return (temp);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)ft_calloc(SIZE_MAX, SIZE_MAX);
    
    // Checking if failed or pass
    if (ptr == NULL) {
        printf("Allocation Failed\n");
        exit(0);
    }
        
     // Print the array
    for (int i = 0; i < 6; i++)
        printf("%d ", ptr[i]);
	free(ptr);
	printf("\n");

    // char *ptr2 = ft_calloc(5, sizeof(char));

    // if (ptr2 == NULL) {
    //     printf("Allocation Failed\n");
    //     exit(0);
    // }

	// for (int i = 0; i < 6; i++)
    //     printf("%d ", ptr2[i]);
	// printf("\n");

    // strcpy(ptr2, "Hello");
    // printf("String after cpy: %s\n", ptr2);
    // free(ptr2);

    return 0;
}
	*/