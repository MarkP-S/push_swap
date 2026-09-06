/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:31:50 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 17:45:30 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_env	*ft_env_initialisation(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if(!env)
		ft_error_exit(NULL);
	env->ops_counters = malloc(sizeof(size_t) * 11);
	env->stack_a = malloc(sizeof(t_stack));
	env->stack_b = malloc(sizeof(t_stack));
	if(!(env->ops_counters && env->stack_a && env->stack_b))
		ft_error_exit(env); 
	return (env);
}

static void	ft_unique(t_env *env, int value)
{
	t_node	*current;
	int		i;

	current = env->stack_a->head;
	i = 0;
	while (i < env->stack_a->length)
	{
		if (current->value == value)
			ft_error_exit(env);
		current = current->next;
		i++;
	}
}

void	ft_stack_append(t_env *env, int value)
{
	t_node	*new_node;

	ft_unique(env, value);
	new_node = malloc(sizeof(t_node));
	if(!new_node)
		ft_error_exit(env);
	new_node->value = value;
	new_node->rank = -1;
	if (!env->stack_a->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		env->stack_a->head = new_node;
		env->stack_a->tail = new_node;
		env->stack_a->length = 1;
		return ;
	}
	new_node->prev = env->stack_a->tail;
	new_node->next = env->stack_a->head;
	env->stack_a->tail->next = new_node;
	env->stack_a->head->prev = new_node;
	env->stack_a->tail = new_node;
	env->stack_a->length++;
}

void	ft_assign_ranks(t_env *env)
{
	int	rank;
	int i;
	t_node	*min_non_ranked;
	t_node	*current_node;

	rank = 0;
	while (rank < env->stack_a->length)
	{
		i = 0;
		min_non_ranked = NULL;
		current_node = env->stack_a->head;
		while (i < env->stack_a->length) {
			if (current_node->rank < 0 && (!min_non_ranked || current_node->value < min_non_ranked->value))
				min_non_ranked = current_node;
			current_node = current_node->next;
			i++;
		}
		min_non_ranked->rank = rank;
		rank++;
	}
}
