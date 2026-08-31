/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:39:21 by ldubok            #+#    #+#             */
/*   Updated: 2026/08/31 17:40:26 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_reverse_rotate_stack(env->stack_a);
	return (1);
}

int	ft_rrb_op(t_environment *env)
{
	if(env->stack_b->length < 2)
		return (1);
	ft_reverse_rotate_stack(env->stack_b);
	return (1);
}

int	ft_rrr_op(t_environment *env)
{
	ft_rra_op(env);
	ft_rrb_op(env);
	return (1);
}
