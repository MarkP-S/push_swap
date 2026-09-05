/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:09:41 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 19:45:01 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("size: %d\n", ft_lstsize(&a));

	return (0);
}
	*/