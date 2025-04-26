/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:53:55 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/26 14:53:56 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stack_node **stack_a)
{
	t_stack_node	*last_node;
	t_stack_node	*second_node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	last_node = get_last_node(*stack_a);
	second_node = (*stack_a)->next;
	(*stack_a)->prev = last_node;
	(*stack_a)->next = NULL;
	last_node->next = *stack_a;
	second_node->prev = NULL;
	*stack_a = second_node;
	return (1);
}
