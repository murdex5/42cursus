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

t_stack_node	*get_node(char *num)
{
	t_stack_node	*node;
	int				len;
	int				nbr;

	nbr = ft_atoi(num);
	len = get_len_except(num);
	node = init_node();
	if (len > 1)
	{
		if (nbr == 0 || nbr == -1)
			return (NULL);
	}
	if (!node)
		return (NULL);
	node->nbr = nbr;
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

t_stack_node	*create_list(char **numbers)
{
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	current = NULL;
	while (numbers[i])
	{
		new_node = get_node(numbers[i]);
		if (!new_node)
			return (free_unbuilt_list(new_node), NULL);
		if (current != NULL)
			current->next = new_node;
		new_node->prev = current;
		new_node->next = NULL;
		current = new_node;
		i++;
	}
	current->next = NULL;
	return (current);
}
