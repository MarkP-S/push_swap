/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:01:08 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 20:52:47 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env *env;

	env = ft_env_initialisation();
	if (argc < 2)
		return (0);
	parse_input(env, argc, argv);
	ft_assign_ranks(env);
	compute_disorder(env);
	run_algo(env);
	print_benchmark(env);
	return (0);
}

	// while (env->stack_a->length)
	// {
	// 	ft_printf_fd(1, "%d\n", env->stack_a->head->value);
	// 	ft_pop_stack(env->stack_a);
	// }
	// ft_free_memory(env);