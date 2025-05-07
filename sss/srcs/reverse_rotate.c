/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:47:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/26 15:47:12 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stack_node **stack_a, bool to_print)
{
	t_stack_node	*last_node;
	t_stack_node	*second_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	last_node = get_last_node(*stack_a);
	second_last = last_node->prev;
	second_last->next = NULL;
	(*stack_a)->prev = last_node;
	last_node->prev = NULL;
	last_node->next = *stack_a;
	*stack_a = last_node;
	if (to_print == true)
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack_node **stack_b, bool to_print)
{
	t_stack_node	*last_node;
	t_stack_node	*second_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	last_node = get_last_node(*stack_b);
	second_last = last_node->prev;
	second_last->next = NULL;
	(*stack_b)->prev = last_node;
	last_node->prev = NULL;
	last_node->next = *stack_b;
	*stack_b = last_node;
	if (to_print == true)
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (rra(stack_a, false) && rrb(stack_b, false))
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
