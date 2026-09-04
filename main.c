/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 21:01:08 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/04 21:15:04 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	
	i = 0;
	while (i < argc)
	{
		i++;
		if (ft_handle_flags(argv[i]))
			continue;
		
	}
	// int	values[] = {3, 4, 1, 0};
	// int *arr = values;

	// t_environment *env = get_test_env(arr);
	// while (env->stack_a->length)
	// {
	// 	printf("%d\n", ft_pop_stack(env->stack_a));
	// }
	// return (0);
}
