/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:54:42 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/02 10:54:44 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		target = NULL;
		while (current_a)
		{
			// Find the smallest number in A that is larger than B's number
			if (current_a->nbr > stack_b->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		// If no larger number found, target the smallest number in A
		stack_b->target_node = (best_match_index == LONG_MAX) ? get_min_node_from(stack_a) : target;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*target;

	if (!*stack_b)
		return ;
	target = (*stack_b)->target_node;
	if ((*stack_b)->above_medium && target->above_medium)
		rotate_both_stacks(stack_a, stack_b, *stack_b);
	else if (!(*stack_b)->above_medium && !target->above_medium)
		rev_rotate_both_stacks(stack_a, stack_b, *stack_b);
	else
	{
		prep_stacks(stack_a, target, 'a');
		prep_stacks(stack_b, *stack_b, 'b');
	}
	pa(stack_a, stack_b);
}

void	min_to_top(t_stack_node **stack)
{
	while ((*stack)->nbr != get_min_node_from(*stack)->nbr)
	{
		if (get_min_node_from(*stack)->above_medium)
			ra(stack, true);
		else
			rra(stack, true);
	}
}