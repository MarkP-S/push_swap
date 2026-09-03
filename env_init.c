/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:31:50 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/02 22:44:34 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_environment	*ft_env_initialisation(void)
{
	t_environment	*env;

	env = malloc(sizeof(t_environment));
	if(!env)
		return (NULL);
	env->mode = ADAPTIVE;
	env->ops_counters = malloc(sizeof(size_t) * 11);
	env->benchmark_on = 0;
	env->stack_a = malloc(sizeof(t_stack));
	env->stack_b = malloc(sizeof(t_stack));
	if(!(env->ops_counters && env->stack_a && env->stack_b))
		return (0); //should free whole env if any fails
	env->stack_a->length = 0;
	env->stack_b->length = 0;
	//All ops counters should be set to 0 to start?
	//Do head and tail need to be set to null at first?
	return (env);
}

void	ft_assign_ranks(t_environment *env)
{
	int	i;
	t_node	*min_non_ranked;
	t_node	*current_node;

	i = 0;
	min_non_ranked = env->stack_a->head;
	while (i < env->stack_a->length)
	{
		while (min_non_ranked->rank >= 0)
			min_non_ranked = min_non_ranked->next;
		current_node = env->stack_a->head;
		while (current_node->next != env->stack_a->head)
		{
			if (current_node->rank < 0 && current_node->value < min_non_ranked->value)
				min_non_ranked = current_node;
			current_node = current_node->next;
		}
		min_non_ranked->rank = i;
		i++;
	}
}
