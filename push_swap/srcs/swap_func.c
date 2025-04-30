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

int	sa(t_stack_node **stack_a, bool to_print)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	first = *stack_a;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack_a = second;
	if (to_print == true)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_stack_node **stack_b, bool to_print)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	first = *stack_b;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack_b = second;
	if (to_print == true)
		ft_printf("sb\n");
	return (1);
}

int	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (sa(stack_a, false) && sb(stack_b, false))
	{
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}
