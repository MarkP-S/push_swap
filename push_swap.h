/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 14:09:05 by ldubok            #+#    #+#             */
/*   Updated: 2026/08/26 17:10:47 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

enum e_mode
{
	SIMPLE, // 0
	MEDIUM, // 1
	COMPLEX, // 2
	ADAPTIVE, // 3
};

enum e_ops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_benchmark
{
	enum e_mode	mode;
	size_t		*ops_counters;
	// benchmark mode
	int			benchmark_on;
}	t_benchmark;

typedef struct s_node
{
	int				*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;


// stack operations
int	ft_swap_stack(t_stack *st);
int ft_pop_stack(t_stack *st);
int	ft_push_stack(t_stack *st, int value);
int	ft_rotate_stack(t_stack *st);
int ft_reverse_rotate_stack(t_stack *st);


