/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 22:08:01 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 22:27:21 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_disorder(t_environment *env)
{
	int		mistakes;
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
