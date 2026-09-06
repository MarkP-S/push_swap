/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 22:08:01 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 22:33:02 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_disorder(t_env *env)
{
	float		mistakes;
	int		i;
	int		j;
	t_node	*first;
	t_node	*second;

	i = 0;
	mistakes = 0;
	first = env->stack_a->head;
	while (i < env->stack_a->length)
	{
		second = first->next;
		j = i + 1;
		while (j < env->stack_a->length)
		{
			if (first->value > second->value)
				mistakes += 1;
			second = second->next;
			j++;
		}
		first = first->next;
		i++;
	}
	env->disorder = 2 * mistakes / (env->stack_a->length * (env->stack_a->length - 1));
}

void	run_algo(t_env *env)
{
	if (env->mode == ADAPTIVE)
	{
		if (env->disorder < 0.2)
			env->algo_used = SIMPLE;
		else if (env->disorder < 0.5)
			env->algo_used = MEDIUM;
		else
			env->algo_used = COMPLEX;
	}
	if (env->stack_a->length == 3)
		sort_three(env);
	else if (env->stack_a->length == 5)
		sort_five(env);
	else if (env->algo_used == SIMPLE)
		selection_sort(env);
	else if (env->algo_used == MEDIUM)
		chunk_sort(env);
	else if (env->algo_used == COMPLEX)
		radix_sort(env);
}
