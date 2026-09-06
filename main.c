/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:01:08 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 19:38:47 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main()
int	main(int argc, char **argv)
{
	t_env *env;

	env = ft_env_initialisation();
	if (argc < 2)
		return (0);
	parse_input(env, argc, argv);
	ft_assign_ranks(env);
	compute_disorder(env);
	radix_sort(env);
	print_benchmark(env);
	while (env->stack_a->length)
	{
		ft_printf_fd(1, "%d\n", env->stack_a->head->value);
		ft_pop_stack(env->stack_a);
	}
	ft_free_memory(env);
	return (0);
}

	// rank();
	// run_algo(env); //calc_disorder->pick an algo->run_simple/meedium/complex
	// print_bench();
	// ft_error_exit(env);
	// int	values[] = {3, 4, 1, 0};
	// int *arr = values;

	// t_env *env = get_test_env(arr);
	// while (env->stack_a->length)
	// {
	// 	ft_printf_fd(1, "%d\n", ft_pop_stack(env->stack_a));
	// }
	// ft_printf_fd(1, "mode%d", env->mode);
	// return (0);