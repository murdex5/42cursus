/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:31:26 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/24 10:31:28 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*get_first_node(t_stack_node *node)
{
	while (node && node->prev)
		node = node->prev;
	return (node);
}

t_stack_node	*get_last_node(t_stack_node *node)
{
	t_stack_node *current;

	current = node;
	while (current && (current->next != NULL))
		current = current->next;
	return (current);
}