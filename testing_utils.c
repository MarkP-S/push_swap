/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:48:05 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 17:34:58 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_environment	*get_test_env(int *array)
{
	int				i;
	t_environment	*env;

	i = 0;
	env = ft_env_initialisation();
	while (array[i])
	{
		ft_stack_append(env, array[i]);
		i++;
	}
	return (env);
}

