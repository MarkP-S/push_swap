/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:30:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 16:24:11 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_swap_stack(env->stack_a);
	print_op(env, SA);
	return (1);
}

int	ft_sb_op(t_environment *env)
{
	if(env->stack_b->length < 2)
		return (1);
	ft_swap_stack(env->stack_b);
	print_op(env, SB);
	return (1);
}

int	ft_ss_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_swap_stack(env->stack_a);
	if(env->stack_b->length < 2)
		return (1);
	ft_swap_stack(env->stack_b);
	print_op(env, SS);
	return (1);
}
