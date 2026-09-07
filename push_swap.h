/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 14:09:05 by ldubok            #+#    #+#             */
/*   Updated: 2026/09/07 18:08:42 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

enum e_mode
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
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

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		length;
}	t_stack;

typedef struct s_env
{
	enum e_mode	mode;
	enum e_mode	algo_used;
	size_t		*ops_counters;
	int			total_ops;
	int			benchmark_flag;
	int			mode_flag;
	int			stack_a_is_str_flag;
	float		disorder;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_env;

// stack operations
void	ft_swap_stack(t_stack *st);
void	ft_pop_stack(t_stack *st);
void	ft_push_stack(t_env *env, t_stack *st, int value, int rank);
void	ft_rotate_stack(t_stack *st);
void	ft_reverse_rotate_stack(t_stack *st);
void	ft_stack_append(t_env *env, int value);

//	initiatization, input reading, preprocesing, exit
t_env	*ft_env_initialisation(void);
void	parse_input(t_env *env, int argc, char **argv);
void	ft_assign_ranks(t_env *env);
int		ft_handle_flags(t_env *env, char *arg);
int		ft_handle_str(t_env *env, char *arg);
void	compute_disorder(t_env *env);
void	ft_free_memory(t_env *env);
void	ft_error_exit(t_env *env);

//	push operations
int		ft_pa_op(t_env *env);
int		ft_pb_op(t_env *env);

//	swap operations
int		ft_sa_op(t_env *env);
int		ft_sb_op(t_env *env);
int		ft_ss_op(t_env *env);

//	rotate operations
int		ft_ra_op(t_env *env);
int		ft_rb_op(t_env *env);
int		ft_rr_op(t_env *env);

//	rotate operations
int		ft_rra_op(t_env *env);
int		ft_rrb_op(t_env *env);
int		ft_rrr_op(t_env *env);

//	algorithms
void	selection_sort(t_env *env);
void	sort_three(t_env *env);
void	run_algo(t_env *env);
void	radix_sort(t_env *env);
void	chunk_sort(t_env *env);
void	sort_five(t_env *env);

//	printing
void	print_op(t_env *env, enum e_ops op);
void	print_float(t_env *env);
void	print_benchmark(t_env *env);

#endif