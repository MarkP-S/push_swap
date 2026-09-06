/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:37:03 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 16:10:13 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stack(t_stack *st)
{
	int	temp;

	temp = st->head->value;
	st->head->value = st->head->next->value;
	st->head->next->value = temp;
	temp = st->head->rank;
	st->head->rank = st->head->next->rank;
	st->head->next->rank = temp;
}

void ft_pop_stack(t_stack *st)
{
	int		popped;
	t_node	*node_to_free;

	popped = st->head->value;
	node_to_free = st->head;
	if (st->head == st->tail)
	{
		st->head = NULL;
		st->tail = NULL;
	}
	else
	{
		st->head = st->head->next;
		st->head->prev = st->tail;
		st->tail->next = st->head;
	}
	free(node_to_free);
	st->length--;
}

void	ft_push_stack(t_env *env, t_stack *st, int value, int rank)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if(!new_node)
		ft_error_exit(env);
	new_node->value = value;
	new_node->rank = rank;
	if (!st->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		st->head = new_node;
		st->tail = new_node;
		st->length = 1;
	}
	new_node->prev = st->tail;
	new_node->next = st->head;
	st->tail->next = new_node;
	st->head->prev = new_node;
	st->head = new_node;
	st->length++;
}

void	ft_rotate_stack(t_stack *st)
{
	st->head = st->head->next;
	st->tail = st->tail->next;
}

void ft_reverse_rotate_stack(t_stack *st)
{
	st->tail = st->tail->prev;
	st->head = st->head->prev;
	return (1);
}