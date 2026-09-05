/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:31:50 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 21:40:59 by ldubok           ###   ########.fr       */
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
	env->benchmark_flag = 0;
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


static void	ft_unique(t_environment *env, int value)
{
	t_node	*current;
	int		i;

	current = env->stack_a->head;
	i = 0;
	while (i < env->stack_a->length)
	{
		if (current->value == value)
			exit(1);
		current = current->next;
		i++;
	}
}

int		ft_stack_append(t_environment *env, int value)
{
	t_node	*new_node;

	ft_unique(env, value);
	new_node = malloc(sizeof(t_node));
	if(!new_node)
		exit(1);
	new_node->value = value;
	new_node->rank = -1;
	if (!env->stack_a->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		env->stack_a->head = new_node;
		env->stack_a->tail = new_node;
		env->stack_a->length = 1;
		return (1);
	}
	new_node->prev = env->stack_a->tail;
	new_node->next = env->stack_a->head;
	env->stack_a->tail->next = new_node;
	env->stack_a->head->prev = new_node;
	env->stack_a->tail = new_node;
	env->stack_a->length++;
	return (1);
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
