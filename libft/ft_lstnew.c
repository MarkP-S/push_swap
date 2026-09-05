/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:11:57 by mapearso          #+#    #+#             */
/*   Updated: 2026/07/23 19:45:12 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *content = "Testing ft_lstnew!";
    
    t_list *new_node = ft_lstnew(content);

    if (new_node == NULL)
    {
        printf("Test Failed: Memory allocation returned NULL.\n");
        return (1);
    }

    printf("Node Address: %p\n", (void *)new_node);
    printf("Node Content: %s\n", (char *)new_node->content);
    printf("Next Pointer: %p\n", (void *)new_node->next);

    free(new_node);
    return (0);
}
	*/
