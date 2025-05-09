/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:27:52 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/09 09:27:53 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*get_target_min(long best_match, t_stack_node *target_node,
		t_stack_node *node)
{
	if (best_match == LONG_MIN)
		return (get_max_node_from(node));
	else
		return (target_node);
}

t_stack_node	*get_target_max(long best_match, t_stack_node *target_node,
		t_stack_node *node)
{
	if (best_match == LONG_MAX)
		return (get_min_node_from(node));
	else
		return (target_node);
}

void	check_above_medium(t_stack_node **stack, int len, int *cost_a,
		int *cost_b)
{
	if ((*stack)->target_node->above_medium)
		*cost_b = (*stack)->target_node->index;
	else
		*cost_b = len - (*stack)->target_node->index;
	if ((*stack)->above_medium == (*stack)->target_node->above_medium)
	{
		if (*cost_a > *cost_b)
			(*stack)->push_cost = *cost_a;
		else
			(*stack)->push_cost = *cost_b;
	}
	else
		(*stack)->push_cost = *cost_a + *cost_b;
}
