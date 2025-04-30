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

int	count_stack(t_stack_node *node)
{
	int				i;
	t_stack_node	*current;

	current = node;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

