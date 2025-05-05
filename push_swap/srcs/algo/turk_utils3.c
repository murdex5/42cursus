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

static void	cost_analysis_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	a_len;
	int	b_len;
	int	cost_a;
	int	cost_b;

	a_len = count_stack(stack_a);
	b_len = count_stack(stack_b);
	while (stack_b)
	{
		cost_b = stack_b->index;
		if (!(stack_b->above_medium))
			cost_b = b_len - stack_b->index;
		if (stack_b->target_node)
		{
			cost_a = stack_b->target_node->index;
			if (!(stack_b->target_node->above_medium))
				cost_a = a_len - stack_b->target_node->index;
			if (stack_b->above_medium == stack_b->target_node->above_medium)
				stack_b->push_cost = (cost_a > cost_b) ? cost_a : cost_b;
			else
				stack_b->push_cost = cost_a + cost_b;
		}
		else
			stack_b->push_cost = cost_b;
		stack_b = stack_b->next;
	}
}

static void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->nbr > stack_b->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = get_min_node_from(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
	cost_analysis_b(stack_a, stack_b);
	set_cheapest(stack_b);
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_from(*stack_b);
	if (cheapest_node->above_medium && cheapest_node->target_node->above_medium)
		rotate_both_stacks(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_medium)
		&& !(cheapest_node->target_node->above_medium))
		rev_rotate_both_stacks(stack_a, stack_b, cheapest_node);
	prep_stacks(stack_b, cheapest_node, 'b');
	prep_stacks(stack_a, cheapest_node->target_node, 'a');
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