/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:57:07 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/02 22:41:35 by mapearso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Sort three numbers
If top is biggest then move it to the back
else if mid is biggest, shift everything down, leaving mid as last
If new top is bigger than mid, swap top and mid
conditions 1 and 3 hit: 5 4 3  ->  4 3 5   ->   3 4 5
condition 3 hit: 4 3 5  ->  3 4 5
condition 2 hit: 4 5 3  ->  3 4 5
*/

void	sort_three(t_environment *env)
{
	int	top;
	int	mid;
	int	bot;

	if (env->stack_a->length != 3)
		return ;

	top = env->stack_a->head->value;
	mid = env->stack_a->head->next->value;
	bot = env->stack_a->head->next->next->value;

	if (top >= mid && top >= bot)
		ft_ra_op(env);
	else if (mid >= top && mid >= bot)
		ft_rra_op(env);
	if (env->stack_a->head->value > env->stack_a->head->next->value)
		ft_sa_op(env);
}
