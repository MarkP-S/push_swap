/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:56:11 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 19:41:21 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("second");
	b = ft_lstnew("first");

	a->next = NULL;
	ft_lstadd_front(&a, b);

	printf("%s\n", (char *)a->content);
	printf("%s\n", (char *)a->next->content);

	free(a->next);
	free(a);

	return (0);
}
*/