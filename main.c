/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:01:08 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 17:45:01 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main()
{
	// int i;
	// t_environment *env;

	// env = ft_env_initialisation();
	// i = 0;
	// if (argc < 2)
	// 	exit(1);
	// while (i < argc)
	// {
	// 	i++;
	// 	if (ft_handle_flags(env, argv[i]))
	// 		continue;
	// 	if (ft_handle_string(env, argv[i]))
	// 		continue;
	// 	if (ft_handle_num(env, argv[i]))
	// 		continue;
	// 	exit(1);
	// }
	// rank();
	// run_algo(env); //calc_disorder->pick an algo->run_simple/meedium/complex
	// print_bench();
	// exit(1);
	int	values[] = {3, 4, 1, 0};
	int *arr = values;

	t_environment *env = get_test_env(arr);
	while (env->stack_a->length)
	{
		printf("%d\n", ft_pop_stack(env->stack_a));
	}
	return (0);
}
