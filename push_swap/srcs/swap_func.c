/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:45:27 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 11:45:57 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack_node **stack_a)
{
	t_stack_node *first;
	t_stack_node *second;
	t_stack_node *third;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	first = *stack_a;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack_a = second;
	return (1);
}