/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:09:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/04 21:18:21 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_flags(t_environment *env, char *arg)
{
	if (arg == "--bench")
	{
		if(env->benchmark_flag)
			exit(1);
		env->benchmark_flag = 1;
	}
	else
		return (0);
	return (1);
}