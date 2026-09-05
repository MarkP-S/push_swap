/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:51:25 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/28 17:39:33 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear_on_fail(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (ft_lstclear(&new_list, del), NULL);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear_on_fail(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	*duplicate(void *content)
{
	char	*new;

	new = malloc(strlen(content) + 1);
	strcpy(new, content);
	return (new);
}

static void	del(void *content)
{
	free(content);
}

static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*copy;

	lst = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("three")));

	printf("original:\n");
	print_list(lst);

	copy = ft_lstmap(lst, duplicate, del);
	strcpy(copy->content, "changed");

	printf("original: %s\n", lst->content);
	printf("copy: %s\n", copy->content);

	printf("\nmapped:\n");
	print_list(copy);

	ft_lstclear(&lst, del);
	ft_lstclear(&copy, del);

	return (0);
}
*/