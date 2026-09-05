/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:04:55 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 17:46:34 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_op_name(enum e_ops op)
{
    if (op == SA)
        ft_printf("sa\n");
    else if (op == SB)
        ft_printf("sb\n");
    else if (op == SS)
        ft_printf("ss\n");
    else if (op == PA)
        ft_printf("pa\n");
    else if (op == PB)
        ft_printf("pb\n");
    else if (op == RA)
        ft_printf("ra\n");
    else if (op == RB)
        ft_printf("rb\n");
    else if (op == RR)
        ft_printf("rr\n");
    else if (op == RRA)
        ft_printf("rra\n");
    else if (op == RRB)
        ft_printf("rrb\n");
    else if (op == RRR)
        ft_printf("rrr\n");
}

void    print_op(t_environment *env, enum e_ops op)
{
    if (!env || !env->ops_counters)
        return ;
    env->ops_counters[op]++;
    env->total_ops++;
    print_op_name(op);
}