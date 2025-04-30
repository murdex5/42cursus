/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:11:30 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/24 10:11:34 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*init_node(void)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack_node	*get_node(char *num, int i)
{
	t_stack_node	*node;
	int i;

	i = 0;
	node = init_node();
	if (!node)
		return (NULL);
	node->nbr = ft_atoi(num);
	return (node);
}

t_stack_node	*build_list(t_stack_node *node)
{
	t_stack_node	*new_list;
	t_stack_node	*prev_list;

	if (!node)
		return (NULL);
	prev_list = node;
	while (prev_list->prev)
	{
		new_list = prev_list;
		prev_list = prev_list->prev;
		prev_list->next = new_list;
	}
	return (prev_list);
}

t_stack_node	*create_list(int argc, char **argv, int len, char **numbers)
{
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	current = NULL;
	while (numbers[i] != NULL)
	{
		new_node = get_node(numbers[i], i);
		if (current != NULL)
			current->next = new_node;
		current = new_node;
	}
	return (current);
}
