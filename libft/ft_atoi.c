/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:27:25 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/28 17:31:50 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		final_number;

	i = 0;
	final_number = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		final_number = (final_number * 10) + (nptr[i] - '0');
		i++;
	}
	final_number *= sign;
	return (final_number);
}
/*
#include <stdio.h>

int main(void){
	//create isspace(3) to check for whitespace
	//nptring can have + or - before, 
	//read nptring until non-confirming character found and returns
	//number thus far
	//no handling of under or overflow
	//a conversion of - '0' will make each char an int
	char *tests[] = {
		"",
		" ",
		"a",
		"+a",
		"+",
		"-",
		" +-",
		"1",
		"123456789",
		"     		42",
		"  +42",
		"  -42",
		"asfdhjk42",
		" 42sdfgjk24  ",
		0};
	char **test = tests;
	while(*test)
	{	
    	//char nptr[] = "     ---0";
   		int result = ft_atoi(*test);
    	printf("For nptring: %s|The resulting int is: %d\n", *test, result);
		test++;
	}
}
*/