/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:39:21 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/07 17:58:17 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra_op(t_env *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_reverse_rotate_stack(env->stack_a);
	print_op(env, RRA);
	return (1);
}

int	ft_rrb_op(t_env *env)
{
	if(env->stack_b->length < 2)
		return (1);
	ft_reverse_rotate_stack(env->stack_b);
	print_op(env, RRB);
	return (1);
}

int	ft_rrr_op(t_env *env)
{
	if(env->stack_a->length >= 2)
		ft_reverse_rotate_stack(env->stack_a);
	if(env->stack_b->length >= 2)
		ft_reverse_rotate_stack(env->stack_b);
	print_op(env, RRR);
	return (1);
}
