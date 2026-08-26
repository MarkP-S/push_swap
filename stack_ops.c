/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:37:03 by ldubok            #+#    #+#             */
/*   Updated: 2026/08/26 13:38:56 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_stack(t_stack *st)
{
	int	temp;

	if (!(*st))
		return (0);
	if (!(*st->head->next))
		return (0);
	temp = st->head->content;
	st->head->content = st->head->next->content;
	st->head->next->content = temp;
	return (1);
}

int ft_pop_stack(t_stack *st)
{
	int		popped;
	t_node	*node_to_free;

	if (!(*st))
		return (0);
	if (!st->head)
		return (0);
	popped = st->head->content;
	node_to_free = st->head;
	st->head = st->head->next;
	if (st->head)
		st->head->prev = NULL;
	free(node_to_free);
	return (popped);
}

int	ft_push_stack(t_stack *st, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return (0);
	new_node->content = value;
	new_node->prev = NULL;
	new_node->next = st->head;
	st->head->prev = new_node;
	st->head = new_node;
	return (1);
}
