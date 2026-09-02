/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:30:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/02 21:15:04 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa_op(t_environment *env)
{
	if(env->stack_a->length < 2)
		return (1);
	ft_swap_stack(env->stack_a);
	return (1);
}

int	ft_sb_op(t_environment *env)
{
	if(env->stack_b->length < 2)
		return (1);
	ft_swap_stack(env->stack_b);
	return (1);
}

int	ft_ss_op(t_environment *env)
{
	ft_sa_op(env);
	ft_sb_op(env);
	return (1);
}
