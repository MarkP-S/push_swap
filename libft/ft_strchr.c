/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:59:29 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/25 01:11:09 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			a;

	a = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    // define a string
    const char* str = "GeeksforGeeks";
    // define a char ch to be searched in str
    char ch = 's';

    // Use strchr to find the first occurrence of the
    // character 's'
    const char* result = strchr(str, ch);

    if (result != NULL) {
        // Calculate the position by subtracting the base
        // pointer from the result pointer
        printf("Character '%c' found at position: %ld\n",
               ch, result - str);
    }
    else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
	*/