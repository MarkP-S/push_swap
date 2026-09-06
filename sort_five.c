/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:23:13 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 22:41:00 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_env *env)
{
	while (env->stack_a->head->rank)
		ft_ra_op(env);
	ft_pb_op(env);
	while (env->stack_a->head->rank != 1)
		ft_ra_op(env);
	ft_pb_op(env);
	sort_three(env);
	ft_pa_op(env);
	ft_pa_op(env);
}
