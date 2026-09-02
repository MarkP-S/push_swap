/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 20:31:50 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/02 17:55:55 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_environment	*ft_env_initialisation()
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
		return (0);
	env->stack_a->length = 0;
	env->stack_b->length = 0;
	return (env);
}
