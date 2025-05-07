/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:36:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/02 10:36:53 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_both_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rev_rotate_both_stacks(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	prep_stacks(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (top_node->above_medium)
		{
			if (stack_name == 'a')
				ra(stack, true);
			else
				rb(stack, true);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack, true);
			else
				rrb(stack, true);
		}
	}
}