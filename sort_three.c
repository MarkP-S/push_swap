/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubok <ldubok@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:57:01 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/02 22:33:41 by ldubok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_environment *env)
{
	int	top;
	int	mid;
	int	bot;

	if (env->stack_a.length != 3)
		return ;

	top = env->stack_a.head->value;
	mid = env->stack_a.head->next->value;
	bot = env->stack_a.head->next->next->value;

	if (top >= mid && top >= bot)
		ft_ra_op(env);
	else if (mid >= top && mid >= bot)
		ft_rra_op(env);
	if (env->stack_a.head->value > mid = env->stack_a.head->next->value)
		ft_sa_op(env);
}