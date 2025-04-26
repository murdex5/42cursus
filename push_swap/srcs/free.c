/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:56:32 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/24 11:56:47 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_list(int **a, int len)
{
	while (len > 0)
	{
		free(a[len]);
		len--;
	}
	free(a);
	return (1);
}

void	free_node(t_stack_node *node)
{
	if (!node)
		return ;
	free(node);
}

void	free_node_list(t_stack_node *node)
{
	t_stack_node	*temp;

	if (!node)
		return ;
	if (node->next == NULL && node->prev == NULL)
	{
		free(node);
		return ;
	}
	node = get_first_node(node);
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
