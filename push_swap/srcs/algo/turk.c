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

	current = node;
	while (current && current->next)
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

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	min = get_min_node_from(*stack_a);
	max = get_max_node_from(*stack_a);
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
	return (1);
}

int	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int len_a;

	len_a = count_stack(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes(*stack_a, *stack_b);
	}
	return (0);
}
