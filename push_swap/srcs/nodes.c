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
	node->target_node = NULL;
	node->cheapest = false;
	node->push_cost = 0;
	return (node);
}

t_stack_node	*get_node(char *num_str)
{
	t_stack_node	*node_ptr;
	long long		parsed_val;

	if (!ft_parse_and_validate_long(num_str, &parsed_val))
		return (NULL);
	if (parsed_val > INT_MAX || parsed_val < INT_MIN)
		return (NULL);
	node_ptr = init_node();
	if (!node_ptr)
		return (NULL);
	node_ptr->nbr = (int)parsed_val;
	return (node_ptr);
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

t_stack_node	*create_list(char **numbers)
{
	t_stack_node	*current;
	t_stack_node	*new_node;
	t_stack_node	*head;
	int				i;

	i = 0;
	current = NULL;
	head = NULL;
	while (numbers[i])
	{
		new_node = get_node(numbers[i]);
		if (!new_node)
			return (free_unbuilt_list(head), NULL);
		if (current != NULL)
			current->next = new_node;
		else
			head = new_node;
		new_node->prev = current;
		new_node->next = NULL;
		current = new_node;
		i++;
	}
	return (current);
}
