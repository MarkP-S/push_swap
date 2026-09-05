/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:09:55 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/05 21:53:30 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_flags(t_environment *env, char *arg)
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

// static int	ft_is_str(t_environment *env, char *arg)
// {
// 	int	i;
// 	int	count_words;
// 	int flag;
	
// 	i = 0;
// 	flag = 0;
// 	count_words = 0;
// 	while(arg[i])
// 	{
// 		if(arg[i] != ' ' && (i == 0 || arg[i - 1] == ' '))
// 			count_words++;
// 		i++;
// 	}
// 	if (count_words > 1)
// 		flag = 1;
// 	return (flag);
// }

static int	ft_handle_num(t_environment *env, char *arg, int len)
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
		exit(1);
	while(i < len)
	{
		if(!ft_isdigit(arg[i]))
			exit(1);
		value = value * 10 + (arg[i] - '0');
		if ((sign > 0 && value > INT_MAX) || (sign < 0 || -value < INT_MIN))
			exit(1);
		i++;
	}
	value *= sign;
	ft_stack_append(env, value);
	return (1);
}

int	ft_handle_str(t_environment *env, char *arg)
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
		{
			len++;
		}
		i++;
	}
	if(len > 0)
	{
		ft_handle_num(env, arg + i - len, len);
	}
	return (1);
}

