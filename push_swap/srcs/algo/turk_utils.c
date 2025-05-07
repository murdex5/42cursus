/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:56:41 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/28 11:56:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_target_node_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		current_b = stack_b;
		target_node = NULL;
		while (current_b)
		{
			if (current_b->nbr < stack_a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		// Change this if statement
		if (target_node == NULL && stack_b)
			stack_a->target_node = get_max_node_from(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	cost_analysis(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	a_len;
	int	b_len;
	int	cost_a;
	int	cost_b;

	a_len = count_stack(stack_a);
	b_len = count_stack(stack_b);
	while (stack_a)
	{
		cost_a = stack_a->index;
		if (!(stack_a->above_medium))
			cost_a = a_len - stack_a->index;
		// Check if target_node exists (it might not if stack_b is empty)
		if (stack_a->target_node)
		{
			cost_b = stack_a->target_node->index;
			if (!(stack_a->target_node->above_medium))
				cost_b = b_len - stack_a->target_node->index;
			// b_len is needed here
			if (stack_a->above_medium == stack_a->target_node->above_medium)
			{
				if (cost_a > cost_b)
					stack_a->push_cost = cost_a;
				else
					stack_a->push_cost = cost_b;
			}
			else
			{
				stack_a->push_cost = cost_a + cost_b;
			}
		}
		else // stack_b is empty, target_node is NULL
		{
			// Cost is just the cost to bring the node to the top of A
			stack_a->push_cost = cost_a;
		}
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*current;

	long cheapest_value = LONG_MAX; // Initialize to max value
	cheapest_node = NULL;
	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	current = stack;
	while (current)
	{
		if (current->push_cost < cheapest_value)
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node) // Check if a cheapest node was found
		cheapest_node->cheapest = true;
}

void	init_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_node_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}
