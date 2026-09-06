/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:04:55 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/06 21:20:59 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_op_name(int fd, enum e_ops op)
{
    if (op == SA)
        ft_printf_fd(fd, "sa");
    else if (op == SB)
        ft_printf_fd(fd, "sb");
    else if (op == SS)
        ft_printf_fd(fd, "ss");
    else if (op == PA)
        ft_printf_fd(fd, "pa");
    else if (op == PB)
        ft_printf_fd(fd, "pb");
    else if (op == RA)
        ft_printf_fd(fd, "ra");
    else if (op == RB)
        ft_printf_fd(fd, "rb");
    else if (op == RR)
        ft_printf_fd(fd, "rr");
    else if (op == RRA)
        ft_printf_fd(fd, "rra");
    else if (op == RRB)
        ft_printf_fd(fd, "rrb");
    else if (op == RRR)
        ft_printf_fd(fd, "rrr");
}

static const char	*get_mode_name(enum e_mode mode, enum e_mode algo_used)
{
	if (mode == ADAPTIVE)
	{
		if (algo_used == SIMPLE)
			return ("adaptive / O(n^2)");
		else if (algo_used == MEDIUM)
			return ("adaptive / O(n*sqrt(n))");
		else if (algo_used == COMPLEX)
			return ("adaptive / nlog n");
		return ("adaptive / unknown");
	}
	if (mode == SIMPLE)
		return ("simple / O(n^2)");
	if (mode == MEDIUM)
		return ("medium / O(n*sqrt(n))");
	if (mode == COMPLEX)
		return ("complex / nlog n");
	return ("unknown");
}


void    print_op(t_env *env, enum e_ops op)
{
    if (!env || !env->ops_counters)
        return ;
    env->ops_counters[op]++;
    env->total_ops++;
	if (!env->benchmark_flag)
	{
    	print_op_name(1, op);
		ft_printf_fd(1, "\n");
	}
}

void	print_float(t_env *env)
{
int		whole;
int		decimal;
float	value;

value = env->disorder * 100;
whole = (int)value;
decimal = (int)((value - whole) * 100);

ft_printf_fd(2, "%d.", whole);
if (decimal < 10)
	ft_printf_fd(2, "0");
ft_printf_fd(2, "%d", decimal);
ft_printf_fd(2, "%\n");
}

void    print_benchmark(t_env *env)
{
	int		i;
	
	if (!env->benchmark_flag)
		return ;

	ft_printf_fd(2, "disorder: ");
	print_float(env);
	ft_printf_fd(2, "strategy: %s\n", get_mode_name(env->mode, env->algo_used));
    ft_printf_fd(2, "total_ops: %d\n", env->total_ops);

	i = 0;
	while (i < 11)
	{
		print_op_name(2, i);
		ft_printf_fd(2, ": %d  ", env->ops_counters[i]);
		i++;
	}
	ft_printf_fd(2, "\n");
}
