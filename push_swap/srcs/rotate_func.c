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

int	ra(t_stack_node **stack_a, bool to_print)
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
	if (to_print == true)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_stack_node **stack_b, bool to_print)
{
	t_stack_node	*last_node;
	t_stack_node	*second_node;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	last_node = get_last_node(*stack_b);
	second_node = (*stack_b)->next;
	(*stack_b)->prev = last_node;
	(*stack_b)->next = NULL;
	last_node->next = *stack_b;
	second_node->prev = NULL;
	*stack_b = second_node;
	if (to_print == true)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ra(stack_a, false) && rb(stack_b, false))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}