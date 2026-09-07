/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 14:14:37 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/07 18:09:53 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Chunk size sqrt(n)
run through length of stack a
	create chunks, that push ranks within the chunk to b
	Each chunk is sorted in b via selection sort
pull all back from b to a
*/

static void	push_chunk(t_env *env, int start, int end, int size)
{
	int	pushed;

	pushed = 0;
	while (pushed < size)
	{
		if (env->stack_a->head->rank >= start
			&& env->stack_a->head->rank <= end)
		{
			ft_pb_op(env);
			pushed++;
			if (env->stack_b->head->rank < start + size / 2)
				ft_rb_op(env);
		}
		else
			ft_ra_op(env);
	}
}

static int	get_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

static void	move_to_top(t_env *env, int index)
{
	if (index <= env->stack_b->length / 2)
	{
		while (index-- > 0)
			ft_rb_op(env);
	}
	else
	{
		while (index++ < env->stack_b->length)
			ft_rrb_op(env);
	}
}

static int	find_max_rank_index(t_stack *stack)
{
	int		max;
	int		max_i;
	int		i;
	t_node	*current;

	if (!stack || stack->length == 0)
		return (-1);
	current = stack->head;
	max = current->rank;
	max_i = 0;
	i = 0;
	while (i < stack->length)
	{
		if (current->rank > max)
		{
			max = current->rank;
			max_i = i;
		}
		current = current->next;
		i++;
	}
	return (max_i);
}

void	chunk_sort(t_env *env)
{
	int	length;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	current_size;

	length = env->stack_a->length;
	chunk_size = get_chunk_size(length);
	chunk_start = 0;
	while (chunk_start < length)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > length)
			chunk_end = length;
		current_size = chunk_end - chunk_start;
		push_chunk(env, chunk_start, chunk_end - 1, current_size);
		chunk_start = chunk_end;
	}
	while (env->stack_b->length > 0)
	{
		move_to_top(env, find_max_rank_index(env->stack_b));
		ft_pa_op(env);
	}
}
