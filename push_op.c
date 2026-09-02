/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:20:13 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/02 22:34:51 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa_op(t_environment *env)
{
	int		value;
	int		rank;

	if (env->stack_b->length == 0)
		return (1);
	value = env->stack_b->head->value;
	rank = env->stack_b->head->rank;
	ft_pop_stack(env->stack_b);
	ft_push_stack(env->stack_a, value, rank);
	return (1);
}

int	ft_pb_op(t_environment *env)
{
	int		value;
	int		rank;

	if (env->stack_a->length == 0)
		return (1);
	value = env->stack_a->head->value;
	rank = env->stack_a->head->rank;
	ft_pop_stack(env->stack_a);
	ft_push_stack(env->stack_b, value, rank);
	return (1);
}
