/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:39:41 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/02 09:39:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	current_index(t_stack_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = count_stack(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_medium = true;
		else
			node->above_medium = false;
		node = node->next;
		i++;
	}
}

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

int	count_stack(t_stack_node *node)
{
	int i;
	t_stack_node *current;

	current = node;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}