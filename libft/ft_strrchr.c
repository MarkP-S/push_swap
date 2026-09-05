/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 01:12:49 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/25 01:23:20 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*result;
	char			a;

	a = (char) c;
	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			result = (char *) &s[i];
		i++;
	}
	if (s[i] == a)
		result = (char *) &s[i];
	return (result);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    // initializing string
    char str[] = "GeeksforGeeks";

    // character to be searched
    char chr = 'k';

    // Storing pointer returned by
    char* ptr = strrchr(str, chr);

    // getting the position of the character
    if (ptr) {
        printf("Last occurrence of %c in %s is at index %ld",
               chr, str, ptr - str);
    }
    // condition for character not present
    else {
        printf("%c is not present in %s ", chr, str);
    }
    return 0;
}
	*/