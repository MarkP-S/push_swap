/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:33:14 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/07 18:09:14 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_stack *st)
{
	t_node	*current;
	t_node	*next;
	int		i;

	current = st->head;
	i = 0;
	while (i < st->length)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	free(st);
}

void	ft_free_memory(t_env *env)
{
	if (!env)
		return ;
	if (env->ops_counters)
		free(env->ops_counters);
	if (env->stack_a)
		ft_free_stack(env->stack_a);
	if (env->stack_b)
		ft_free_stack(env->stack_b);
	free(env);
}

void	ft_error_exit(t_env *env)
{
	ft_free_memory(env);
	ft_printf_fd(2, "Error\n");
	exit(1);
}

