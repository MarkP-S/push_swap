/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:09:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/06 20:30:25 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_flags(t_env *env, char *arg)
{
	if (!ft_strncmp(arg, "--bench", 7))
	{
		env->benchmark_flag = 1;
	}
	else if (!ft_strncmp(arg, "--adaptive", 10))
	{
		env->mode = ADAPTIVE;
	}
	else if (!ft_strncmp(arg, "--simple", 8))
	{
		env->mode = SIMPLE;
	}
	else if (!ft_strncmp(arg, "--medium", 8))
	{
		env->mode = MEDIUM;
	}
	else if (!ft_strncmp(arg, "--complex", 9))
	{
		env->mode = COMPLEX;
	}
	else
		return (0);
	env->algo_used = env->mode;
	return (1);
}

static int	ft_handle_num(t_env *env, char *arg, int len)
{
	int i;
	long value;
	int sign;

	i = 0;
	value = 0;
	sign = 1;
	if(arg[i] == '-')
		sign = -1;
	if(arg[i] == '-' || arg[i] == '+')
		i++;
	if(!arg[i])
		ft_error_exit(env);
	while(i < len && len < 12)
	{
		if(!ft_isdigit(arg[i]))
			ft_error_exit(env);
		value = value * 10 + (arg[i] - '0');
		i++;
	}
	value *= sign;
	if (value > INT_MAX || value < INT_MIN)
		ft_error_exit(env);
	ft_stack_append(env, value);
	return (1);
}

int	ft_handle_str(t_env *env, char *arg)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	while (arg[i])
	{
		if(arg[i] == ' ')
		{
			if(len > 0)
			{
				ft_handle_num(env, arg + i - len, len);
			}
			len = 0;
		}
		else 
			len++;
		i++;
	}
	if(len > 0)
	{
		ft_handle_num(env, arg + i - len, len);
	}
	return (1);
}

void	parse_input(t_env *env, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		i++;
		if (ft_handle_flags(env, argv[i]))
			continue;
		if (ft_handle_str(env, argv[i]))
			continue;
		ft_error_exit(env);
	}
}
