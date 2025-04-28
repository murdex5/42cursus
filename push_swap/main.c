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

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				len;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_stack_node	*current;

	len = 0;
	if (argc < 2)
		return (error_msg(), 1);
	stack_a = checks(argc, argv, &len);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	sa(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	current = stack_b;
	while (current)
	{
		if (current->nbr)
			ft_printf("%d\n", current->nbr);
		current = current->next;
	}
	free_node_list(stack_a);
	free_node_list(stack_b);
	return (0);
}
