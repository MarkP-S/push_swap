/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 02:19:05 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/28 17:38:38 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_inset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_inset(s1[i], set))
		i++;
	while (i <= j && ft_inset(s1[j], set))
		j--;
	trimmed = ft_substr(s1, i, j - i + 1);
	return (trimmed);
}
/*
#include <stdio.h>

int main(void)
{
	char *string = "stringababaaababab";
	char *set = "abs";
	char *trimmed = ft_strtrim(string, set);
	printf("Resulting string: %s\n", trimmed);

}
	*/