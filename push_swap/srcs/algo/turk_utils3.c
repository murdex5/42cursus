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

void	update_above_medium(t_stack_node *stack)
{
	int	len;
	int	median;
	int	i;

	len = count_stack(stack);
	median = (len + 1) / 2;
	i = 1;
	while (stack)
	{
		stack->above_medium = (i < median);
		stack = stack->next;
		i++;
	}
}

static void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	t_stack_node *current_b = stack_b; // Use a separate pointer for iteration
	while (current_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		target_node = NULL; // Initialize target_node
		while (current_a)
		{
			if (current_a->nbr > current_b->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			current_b->target_node = get_min_node_from(stack_a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next; // Advance the iteration pointer
	}
}

void	init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*current_b;

	current_b = *stack_b;
	if (current_b)
	{
		prep_stacks(stack_a, current_b->target_node, 'a');
		pa(stack_a, stack_b);
	}
}

void	min_to_top(t_stack_node **stack)
{
	t_stack_node *min_node = get_min_node_from(*stack);
	while ((*stack)->nbr != min_node->nbr)
	{
		if (min_node->above_medium)
			ra(stack, true);
		else
			rra(stack, true);
		update_above_medium(*stack);          // Add this line
		min_node = get_min_node_from(*stack); // Update min_node
	}
}