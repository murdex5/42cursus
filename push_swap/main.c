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
#ifdef DEBUG
#endif
int	main(int argc, char **argv)
{
	int				len;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**numbers;

	stack_b = NULL;
	numbers = get_int_checks(argc, argv, &len);
	if (!numbers)
		return (free_list_error(numbers), 0);
	stack_a = checks(argc, numbers);
	if (!stack_a)
		return (0);
	if (!stack_sorted(stack_a))
	{
		if (count_stack(stack_a) == 2)
			sa(&stack_a, true);
		if (count_stack(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	// if (!stack_sorted(stack_a))
	// 	ft_printf("stack is not sorted");
	free_node_list(stack_a);
	free_node_list(stack_b);
	return (0);
}
