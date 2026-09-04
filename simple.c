/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:05:35 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/02 22:42:10 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Selection sort

Find highest value in stack a - create function for this
Move value to top of a - ra if closer to top, rra if closer to bottom - create function
pb to push top of a to top of b

Repeat these steps until a is empty
Push back from b to a until b empty, will refill a with sorted numbers
*/

int	find_min(t_stack *stack_a)
{
	int		min;
	int		min_index;
	int		i;
	t_node	*current;

	if (!stack_a->head || stack_a->length == 0)
		return (-1);
	current = stack_a->head;
	min = current->value;
	min_index = 0;
	i = 0;
	stack_a->head = stack_a->head->next;
	while (i < stack_a->length)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	move_to_top(t_environment *env, int index)
{
	if (index <= env->stack_a->length / 2)
	{
		while (index-- > 0)
			ft_ra_op(env);
	}
	else
	{
		while (index++ < env->stack_a->length)
			ft_rra_op(env);
	}
}

void	selection_sort(t_environment *env)
{
	int	min_index;

	while (env->stack_a->length > 0)
	{
		min_index = find_min(env->stack_a);
		move_to_top(env, min_index);
		ft_pb_op(env);
	}
	while (env->stack_b->length > 0)
		ft_pa_op(env);
}

