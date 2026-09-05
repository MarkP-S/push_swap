/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:20:02 by mapearso          #+#    #+#             */
/*   Updated: 2026/06/25 00:56:24 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int main(void){
//turn upper to lower
//ascii difference always 32, add 32 from upper to get lower
char string[] = "aa???AAAaaa12";
char* result = ft_tolower(string);

printf("Result is: %s", result);
}
*/