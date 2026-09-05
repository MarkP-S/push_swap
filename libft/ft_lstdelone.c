/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:49:10 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 19:45:47 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
#include <stdlib.h>

static void	del(void *content)
{
	printf("freeing: %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	char	*str;
	t_list	*node;

	str = malloc(6);
	strcpy(str, "hello");

	node = ft_lstnew(str);

	ft_lstdelone(node, del);

	printf("done\n");

	return (0);
}
*/