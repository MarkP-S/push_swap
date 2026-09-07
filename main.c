/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:01:08 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/07 10:15:00 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		return (0);
	env = ft_env_initialisation();
	parse_input(env, argc, argv);
	ft_assign_ranks(env);
	compute_disorder(env);
	if (env->disorder > 0)
		run_algo(env);
	print_benchmark(env);
	ft_free_memory(env);
	return (0);
}
