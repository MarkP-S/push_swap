/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:23:40 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/25 01:34:58 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < (n - 1)) && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
    
    int result = ft_strncmp(s1, s2, 5);
    
    printf("%d\n", result);
	printf("%d\n", ft_strncmp("abc", "abc", 3));  // 0
	printf("%d\n", ft_strncmp("abc", "abd", 3));  // < 0
	printf("%d\n", ft_strncmp("abd", "abc", 3));  // > 0
	printf("%d\n", ft_strncmp("abc", "abc", 0));  // 0
	printf("%d\n", ft_strncmp("abc", "abcd", 4));

	
    return 0;
}
*/