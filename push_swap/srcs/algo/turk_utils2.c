/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:26:21 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/02 10:26:22 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_node	*get_cheapest_from(t_stack_node *node)
{
	t_stack_node	*cheapest_node;

	cheapest_node = node;
	while (node)
	{
		if (node->cheapest == true)
			cheapest_node = node;
		node = node->next;
	}
	return (cheapest_node);
}

void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *cheapest_node;

    cheapest_node = get_cheapest_from(*stack_a);
    if (cheapest_node && cheapest_node->target_node)
    {
        if (cheapest_node->above_medium && cheapest_node->target_node->above_medium)
            rotate_both_stacks(stack_a, stack_b, cheapest_node);
        else if (!(cheapest_node->above_medium) && !(cheapest_node->target_node->above_medium))
            rev_rotate_both_stacks(stack_a, stack_b, cheapest_node);
    }
    prep_stacks(stack_a, cheapest_node, 'a');
    if (cheapest_node && cheapest_node->target_node)
        prep_stacks(stack_b, cheapest_node->target_node, 'b');
    pb(stack_a, stack_b);
}
