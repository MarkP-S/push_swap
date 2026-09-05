/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:45:02 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 18:05:58 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	fill_string(char *str, long int num, int len)
{
	int	current;

	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num)
	{
		len--;
		current = (num % 10) + '0';
		str[len] = current;
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long int	num;
	int			num_length;
	char		*num_string;

	num_length = count_digits(n);
	num = n;
	num_string = malloc((num_length + 1) * sizeof(char));
	if (!num_string)
		return (NULL);
	num_string[num_length] = 0;
	if (num == 0)
	{
		num_string[0] = '0';
		return (num_string);
	}
	fill_string(num_string, num, num_length);
	return (num_string);
}
/*
#include <stdio.h>
int main(void)
{
	int num = 12345;
	char *numstr = ft_itoa(num);
	printf("resulting string: %s", numstr);
}
*/