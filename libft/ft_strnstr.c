/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:39:26 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/25 19:18:11 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *) big + i);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Example haystack";
    const char *needle = "hay";
    size_t limit = 20;

    char *result = ft_strnstr(haystack, needle, limit);

    if (result != NULL) {
        printf("Needle found: %p\n", &result);
		printf("Haystack from pointer to needle start: %s\n", result);
    } else
		printf("Needle not found\n");
	return 0;
}
*/