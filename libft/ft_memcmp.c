/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:22:03 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/01 16:37:40 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;
	size_t					i;

	str1 = s1;
	str2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (i < (n - 1)))
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>

int main()
{
    //return 0 if strings equal
    //return negative if s1<s2
    //return positive if s1>s2
	//note usage of n-1 because we iterate from 0 but count characters from 1
    
    char s1[] = "Helh";
    char s2[] = "Helhui";

	char s3[] = {0, 0, 127, 0};
	char s4[] = {0, 0, 42, 0};
    
    //int result = ft_memcmp(s1, s2, 5);
    
    // printf("%d\n", result);
	// printf("%d\n", ft_memcmp("abc", "abc", 3));  // 0
	// printf("%d\n", ft_memcmp("abc", "abd", 3));  // < 0
	// printf("%d\n", ft_memcmp("abd", "abc", 3));  // > 0
	// printf("%d\n", ft_memcmp("abc", "abc", 0));  // 0
	// printf("%d\n", ft_memcmp("abc", "abcd", 4));
	printf("failed test: %d\n", ft_memcmp(s3, s4, 4)); //should not be zero
	
    return 0;
}
*/