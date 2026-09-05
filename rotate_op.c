/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:35:25 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 16:35:13 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_rotate_stack(env->stack_a);
	print_op(env, RA);
	return (1);
}

int	ft_rb_op(t_environment *env)
{
	if(env->stack_b->length < 2)
		return (1);
	ft_rotate_stack(env->stack_b);
	print_op(env, RB);
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
	print_op(env, RR);
	return (1);
}