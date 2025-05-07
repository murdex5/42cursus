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
#ifdef DEBUG // Add this preprocessor directive
		printf("Stack B Nbr: %d, Target Nbr: %d\n", stack_b->nbr,
			stack_b->target_node ? stack_b->target_node->nbr : -1);
#endif
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_stack_node *stack_a, t_stack_node *stack_b)
{

	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
#ifdef DEBUG // Add this preprocessor directive
	t_stack_node	*current;
	current = stack_a;
	printf("Stack A (init_nodes_b):\n");
	while (current)
	{
		printf("Index: %d, Above_medium: %d, Nbr: %d\n", current->index,
			current->above_medium, current->nbr);
		current = current->next;
	}
	current = stack_b;
	printf("Stack B (init_nodes_b):\n");
	while (current)
	{
		printf("Index: %d, Above_medium: %d, Nbr: %d\n", current->index,
			current->above_medium, current->nbr);
		current = current->next;
	}
#endif
}

void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	prep_stacks(stack_a, (*stack_b)->target_node, 'a');
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