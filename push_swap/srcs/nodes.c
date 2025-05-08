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
    long long		val;
    int				i;
    int				sign;
    int				digit_count;

    if (!num_str || !*num_str)
        return (NULL);
    i = 0;
    sign = 1;
    digit_count = 0;
    if (num_str[i] == '+')
        i++;
    else if (num_str[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (!num_str[i]) /* String was only a sign or empty after sign */
        return (NULL);
    val = 0;
    while (num_str[i])
    {
        if (!ft_isdigit(num_str[i])) /* Invalid character */
            return (NULL);
        val = val * 10 + (num_str[i] - '0');
        digit_count++;
        if ((sign == 1 && val > INT_MAX) || \
            (sign == -1 && val > (long long)INT_MAX + 1)) /* Check against absolute INT_MIN */
            return (NULL); 
        i++;
    }
    if (digit_count == 0) 
        return (NULL);
    val *= sign;
    if (val > INT_MAX || val < INT_MIN)
        return (NULL);
    node_ptr = init_node();
    if (!node_ptr)
        return (NULL);
    node_ptr->nbr = (int)val;
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
