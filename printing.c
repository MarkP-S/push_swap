/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:04:55 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/05 16:38:07 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_op_name(enum e_ops op)
{
    if (op == SA)
        printf("sa\n");
    else if (op == SB)
        printf("sb\n");
    else if (op == SS)
        printf("ss\n");
    else if (op == PA)
        printf("pa\n");
    else if (op == PB)
        printf("pb\n");
    else if (op == RA)
        printf("ra\n");
    else if (op == RB)
        printf("rb\n");
    else if (op == RR)
        printf("rr\n");
    else if (op == RRA)
        printf("rra\n");
    else if (op == RRB)
        printf("rrb\n");
    else if (op == RRR)
        printf("rrr\n");
}

void    print_op(t_environment *env, enum e_ops op)
{
    if (!env || !env->ops_counters)
        return ;
    env->ops_counters[op]++;
    env->total_ops++;
    print_op_name(op);
}