/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:27:57 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/07 18:26:25 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_env *env)
{
	int	bit;
	int	i;

	bit = 1;
	while (bit / 2 < env->stack_a->length)
	{
		i = 0;
		while (i < env->stack_a->length)
		{
			if (env->stack_a->head->rank & bit)
			{
				i++;
				ft_ra_op(env);
			}
			else
				ft_pb_op(env);
		}
		while (env->stack_b->length)
			ft_pa_op(env);
		bit *= 2;
	}
}
