/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:09:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 19:12:05 by ldubok           ###   ########.fr       */
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

static int	ft_is_str(t_environment *env, char *arg)
{
	int	i;
	int	count_nums;

	i = 0;
	count_nums = 0;
	while(arg[i])
	{
		if((ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+') && (i == 0 || arg[i - 1] == ' '))
			count_nums++;
		i++;
	}
	if (count_nums > 1)
		env->input_is_str_flag = 1;
	return (env->input_is_str_flag);
}

int	ft_handle_str(t_environment *env, char *arg)
{
	if (!ft_is_str)
		return (0);
	
	return (1);
}

int	ft_handle_num(t_environment *env, char *arg)
{
	int i;
	int value;
	int sign;

	i = 0;
	value = 0;
	sign = 1;
	if(arg[i] && arg[i] == '-')
		sign = -1;
	if(arg[i] && (arg[i] == '-' || arg[i] == '+'))
		i++;
	if(!arg[i])
		exit(1);
	while(arg[i])
	{
		if(!ft_isdigit())
		i++;
	}
	return (1);
}