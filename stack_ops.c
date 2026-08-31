/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:37:03 by ldubok            #+#    #+#             */
/*   Updated: 2026/08/31 17:33:18 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_stack(t_stack *st)
{
	int	temp;

	if (!(st))
		return (0);
	temp = st->head->content;
	st->head->content = st->head->next->content;
	st->head->next->content = temp;
	temp = st->head->rank;
	st->head->rank = st->head->next->rank;
	st->head->next->rank = temp;
	return (1);
}

int ft_pop_stack(t_stack *st)
{
	int		popped;
	t_node	*node_to_free;

	if (!(st))
		return (0);
	popped = st->head->content;
	node_to_free = st->head;
	if (st->head == st->tail)
	{
		st->head = NULL;
		st->tail = NULL
	}
	else
	{
		st->head = st->head->next;
		st->head->prev = st->tail;
		st->tail->next = st->head;
	}
	free(node_to_free);
	return (popped);
}

int	ft_push_stack(t_stack *st, int value, int rank)
{
	t_node	*new_node;

	if(!st)
		return (0);
	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return (0);
	new_node->content = value;
	new_node->rank = rank;
	if (!st->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		st->head = new_node;
		st->tail = new_node;
		return (1);
	}
	new_node->prev = st->tail;
	st->tail->next = new_node;
	st->head->prev = new_node;
	st->head = new_node;
	return (1);
}

int	ft_rotate_stack(t_stack *st)
{
	if(!st)
		return (0);
	st->head = st->head->next;
	st->tail = st->tail->next;
	return (1);
}

int ft_reverse_rotate_stack(t_stack *st)
{
	if(!st)
		return (0);
	st->tail = st->tail->prev;
	st->head = st->head->prev;
	return (1);
}