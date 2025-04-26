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

t_stack_node	*get_node(char **argv, int i, t_stack_node *prev)
{
	t_stack_node	*node;

	node = init_node();
	if (!node)
		return (NULL);
	if (ft_strncmp(argv[i + 1], "2147483647", ft_strlen(argv[i + 1])) == 0
		|| ft_strncmp(argv[i + 1], "-2147483648", ft_strlen(argv[i + 1])) == 0)
		return (free_node(node), NULL);
	node->nbr = ft_atoi(argv[i + 1]);
	node->index = i;
	node->prev = prev;
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

t_stack_node	*create_list(int argc, char **argv, int *len)
{
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	if (argc <= 1)
		return (NULL);
	current = NULL;
	while (i < argc - 1)
	{
		new_node = get_node(argv, i, current);
		if (!new_node)
			return (free_unbuilt_list(current), NULL);
		current = new_node;
		i++;
	}
	current = build_list(current);
	*len = argc - 1;
	return (current);
}
