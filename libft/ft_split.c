/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 01:12:25 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/28 17:35:25 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(char const *str, char c)
{
	int	count;
	int	new_word;
	int	i;

	i = 0;
	new_word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && new_word == 0)
		{
			new_word = 1;
			count++;
		}
		else if (str[i] == c)
			new_word = 0;
		i++;
	}
	return (count);
}

static void	free_split(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static	char	**create_word_array(char const *s, char **word_array, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		word_array[j] = ft_substr(s, start, (i - start));
		if (!word_array[j])
		{
			free_split(word_array, j - 1);
			return (0);
		}
		j++;
	}
	word_array[j] = NULL;
	return (word_array);
}

char	**ft_split(char const *s, char c)
{
	char	**word_array;

	if (!s)
		return (0);
	word_array = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!word_array)
		return (NULL);
	return (create_word_array(s, word_array, c));
}
/*
int main()
{
    char *test = ",,,,A,,,string,,,split,,,by,,,commas,,,,";
    char splitter = ',';

    char **result_array = ft_split(test, splitter);
    int i = 0;

    while (result_array[i] != NULL)
    {
        printf("%s\n", result_array[i]);
        i++;
    }
    return (0);
}
*/