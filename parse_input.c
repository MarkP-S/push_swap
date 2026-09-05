/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:09:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 16:01:47 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_flags(t_environment *env, char *arg)
{
	if (arg == "--bench")
	{
		env->benchmark_flag = 1;
	}
	else if (arg == "--adaptive")
	{
		env->mode = ADAPTIVE;
	}
	else if (arg == "--simple")
	{
		env->mode = SIMPLE;
	}
	else if (arg == "--medium")
	{
		env->mode = MEDIUM;
	}
	else if (arg == "--complex")
	{
		env->mode = COMPLEX;
	}
	else
		return (0);
	env->algo_used = env->mode;
	return (1);
}
