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

#include "push_swap.h"

int	sa(int **stack_a, int len)
{
	int	temp;

	if (len < 2)
		return (0);
	temp = *(stack_a)[0];
	*(stack_a[0]) = *(stack_a[1]);
	*(stack_a[1]) = temp;
	return (1);
}

int	sb(int **stack_b, int len)
{
	int	temp;

	if (len < 2)
		return (0);
	temp = *(stack_b[0]);
	*(stack_b[0]) = *(stack_b[1]);
	*(stack_b[1]) = temp;
	return (1);
}

int	ss(int **stack_a, int **stack_b, int a_len, int b_len)
{
	if (!stack_a || !stack_b)
		return (0);
	if (sa(stack_a, a_len) && sb(stack_b, b_len))
		return (1);
	return (0);
}