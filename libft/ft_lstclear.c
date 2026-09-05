/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:49:54 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 19:46:05 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
#include <stdlib.h>

static void	del(void *content)
{
	printf("delete %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("three")));

	ft_lstclear(&lst, del);

	if (lst == NULL)
		printf("list cleared\n");

	return (0);
}
	*/
