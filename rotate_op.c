/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:35:25 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 16:19:15 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_rotate_stack(env->stack_a);
	return (1);
}

int	ft_rb_op(t_environment *env)
{
	if(env->stack_b->length < 2)
		return (1);
	ft_rotate_stack(env->stack_b);
	return (1);
}

int	ft_rr_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_rotate_stack(env->stack_a);
	if(env->stack_b->length < 2)
		return (1);
	ft_rotate_stack(env->stack_b);
	return (1);
}