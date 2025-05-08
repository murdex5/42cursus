/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:51:37 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/28 11:51:39 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	stack_sorted(t_stack_node *node)
{
	t_stack_node	*current;

	if (node == NULL || node->next == NULL)
		return (true); // Empty or single-node stack is considered sorted
	current = node;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (false);
		current = current->next;
	}
	return (true);
}

int	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*min;
	t_stack_node	*max;

	min = get_min_node_from(*stack_a);
	max = get_max_node_from(*stack_a);
	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	if (max->index == 0 && min->index == 2)
	{
		ra(stack_a, true);
		sa(stack_a, true);
	}
	else if (max->index == 1 && min->index == 0)
	{
		rra(stack_a, true);
		sa(stack_a, true);
	}
	else if (max->index == 2 && min->index == 1)
		sa(stack_a, true);
	else if (max->index == 0 && min->index == 1)
		ra(stack_a, true);
	else if (max->index == 1 && min->index == 2)
		rra(stack_a, true);
	else if (!stack_sorted(*stack_a))
		sa(stack_a, true);
	return (1);
}

int	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int	len_a;

    len_a = count_stack(*stack_a);
    if (stack_sorted(*stack_a))
        return (0);
    while (len_a > 3 && !stack_sorted(*stack_a))
    {
        init_nodes(*stack_a, *stack_b);
        move_a_to_b(stack_a, stack_b);
        len_a = count_stack(*stack_a);
    }
    if (len_a == 3 && !stack_sorted(*stack_a))
    {
        current_index(*stack_a);
        sort_three(stack_a);
    }
    while (*stack_b)
    {
        init_nodes_b(*stack_a, *stack_b); 
        move_b_to_a(stack_a, stack_b);    
    }
    if (!stack_sorted(*stack_a) && count_stack(*stack_a) > 0)
    {
        current_index(*stack_a);
        min_to_top(stack_a);
    }
    return (0);
}

// if (len_a-- > 3 && !stack_sorted(*stack_a))
// 		pb(stack_a, stack_b);
// 	if (len_a-- > 3 && !stack_sorted(*stack_a))
// 		pb(stack_a, stack_b);