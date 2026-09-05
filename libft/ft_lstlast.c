/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:46:44 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 19:45:32 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a.content = "one";
	b.content = "two";
	c.content = "three";

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("last: %s\n", (char *)ft_lstlast(&a)->content);

	return (0);
}
*/