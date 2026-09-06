/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 14:14:37 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/06 15:24:21 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Chunk size sqrt(n)
run through length of stack a
	create chunks, that push ranks within the chunk to b(n time complexity)
	
pull all back from b to a
*/

static void	push_chunk(t_environment *env, int start, int end, int size)
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

void	chunk_sort(t_environment *env)
{
	int	chunk_size;
	int	length;
	int	chunk_start;
	int	chunk_end;

	length = env->stack_a->length;
	chunk_size = get_chunk_size(length);
	chunk_start = 0;
	while (chunk_start < length)
	{
		chunk_end = chunk_start + chunk_size - 1;
		if (chunk_end >= length)
			chunk_end = length - 1;
		push_chunk(env, chunk_start, chunk_end, chunk_size);
		chunk_start += chunk_size;
	}
	push_to_a(env);
}