/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapearso <mapearso@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:57:01 by mapearso          #+#    #+#             */
/*   Updated: 2026/09/02 18:15:11 by mapearso         ###   ########.fr       */
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

	top = env->stack_a.head->content;
	mid = env->stack_a.head->next->content;
	bot = env->stack_a.head->next->next->content;

	if (top >= mid && top >= bot)
		ft_ra_op(env);
	else if (mid >= top && mid >= bot)
		ft_rra_op(env);
	if (env->stack_a.head->content > mid = env->stack_a.head->next->content)
		ft_sa_op(env);
}