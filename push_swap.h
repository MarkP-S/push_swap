/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 14:09:05 by ldubok            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/09/05 17:34:33 by ldubok           ###   ########.fr       */
=======
/*   Updated: 2026/09/05 17:46:29 by mapearso         ###   ########.fr       */
>>>>>>> 1e4d0a48a262ef7eaf4731f353c6f2d01b6b2616
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

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

typedef struct s_environment
{
	enum e_mode	mode;
	enum e_mode algo_used;
	size_t		*ops_counters;
	int			total_ops;
	int			benchmark_flag;
	int			mode_flag;
	int			stack_a_is_str_flag;
	float		disorder;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_environment;

// stack operations
int	ft_swap_stack(t_stack *st);
int ft_pop_stack(t_stack *st);
int	ft_push_stack(t_stack *st, int value, int rank);
int	ft_rotate_stack(t_stack *st);
int ft_reverse_rotate_stack(t_stack *st);

//	initiatization, input reading and preprocesing
t_environment	*ft_env_initialisation();
void			ft_assign_ranks(t_environment *env);
int				ft_handle_flags(t_environment *env, char *arg);

//	push operations
int	ft_pa_op(t_environment *env);
int	ft_pb_op(t_environment *env);

//	swap operations
int	ft_sa_op(t_environment *env);
int	ft_sb_op(t_environment *env);
int	ft_ss_op(t_environment *env);

//	rotate operations
int	ft_ra_op(t_environment *env);
int	ft_rb_op(t_environment *env);
int	ft_rr_op(t_environment *env);

//	rotate operations
int	ft_rra_op(t_environment *env);
int	ft_rrb_op(t_environment *env);
int	ft_rrr_op(t_environment *env);

//	testing utils
t_environment	*get_test_env(int *array);

//	algorithms
void	selection_sort(t_environment *env);
void	sort_three(t_environment *env);

//	printing
void    print_op(t_environment *env, enum e_ops op);

#endif