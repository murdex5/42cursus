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
		if (current->nbr < current->next->nbr)
			return (false);
		current = current->next;
	}
	return (true);
}

int	sort_three(t_stack_node **stack_a)
{
	
	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	if (get_max_node_from(stack_a)->index == 0
		&& get_min_node_from(stack_a)->index == 2)
	{
		ra(&stack_a);
		sa(&stack_a);
		ft_printf("ra\nsa\n");
	}
	else if (get_max_node_from(stack_a)->index == 1
		&& get_min_node_from(stack_a)->index == 0)
	{
		rra(&stack_a);
		sa(&stack_a);
		ft_printf("rra\nsa\n");
	}
	else if (get_max_node_from(stack_a)->index == 2
		&& get_min_node_from(stack_a)->index == 1)
	{
		sa(&stack_a);
		ft_printf("sa\n");
	}
		return (1);
}
