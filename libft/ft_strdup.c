/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 02:34:10 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/27 20:29:11 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
	char source[] = "GeeksForGeeks";

	// A copy of source is created dynamically
	// and pointer to copy is returned.
	char* target = ft_strdup(source); 

	printf("%s", target);
	free(target)
	return 0;
}
	*/