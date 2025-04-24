/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:46:26 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 12:25:52 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int				len;
	t_stack_node	*stack_a;
	t_stack_node *stack_b;

	len = 0;
	if (argc < 2)
		return (error_msg(), 1);
	stack_a = checks(argc, argv, &len);
	stack_b = init_node();
	if (!stack_a)
		return (1);
	pb(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	if (stack_b->nbr)
		ft_printf("%d\n", stack_b->nbr);
	free_node_list(stack_a);
	free_node_list(stack_b);
	return (stack_b->nbr);
}
