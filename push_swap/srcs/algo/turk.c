/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:51:37 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/28 11:51:39 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	turk(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if ((!stack_a || !(*stack_a)) || (!stack_b || !(*stack_b)))
		return (0);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
    
}
