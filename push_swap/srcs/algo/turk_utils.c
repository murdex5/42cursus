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

t_stack_node	*get_max_node_from(t_stack_node *node)
{
	t_stack_node	*current;

	current = node;
	while (node)
	{
		if (node->nbr > current->nbr)
			current = node;
		node = node->next;
	}
	return (current);
}

t_stack_node	*get_min_node_from(t_stack_node *node)
{
	t_stack_node	*current;

	current = node;
	while (node)
	{
		if (node->nbr < current->nbr)
			current = node;
		node = node->next;
	}
	return (current);
}

int	do_calcs(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	rotations;

	rotations = 0;
	if (stack_a->nbr > get_max_node_from(stack_b)->nbr)
	{
		
	}
}

int	find_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
}
