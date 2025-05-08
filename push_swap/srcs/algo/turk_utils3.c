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

static void set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
    if (!stack_a)
        return;
    while (stack_b)
    {
        t_stack_node *current_a = stack_a;
        t_stack_node *target_node = NULL;
        long best_match = LONG_MAX;

        while (current_a)
        {
            if (current_a->nbr > stack_b->nbr && current_a->nbr < best_match)
            {
                best_match = current_a->nbr;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        stack_b->target_node = (best_match == LONG_MAX) ? get_min_node_from(stack_a) : target_node;
        stack_b = stack_b->next;
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
