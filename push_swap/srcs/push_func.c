/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:02:47 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/24 10:03:13 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*node_to_move;

	if (!stack_b || !(*stack_b))
		return (0);
	node_to_move = *stack_b;
	*stack_b = node_to_move->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node_to_move->prev = NULL;
	node_to_move->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = node_to_move;
	*stack_a = node_to_move;
	return (1);
}

int	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*node_to_move;

	if (!stack_a || !(*stack_a))
		return (0);
	node_to_move = *stack_a;
	*stack_a = node_to_move->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node_to_move->prev = NULL;
	node_to_move->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = node_to_move;
	*stack_b = node_to_move;
	return (1);
}
