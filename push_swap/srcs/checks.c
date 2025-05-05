/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:55:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/20 13:55:25 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_params(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = ft_strlen(argv[i]);
		k = 0;
		while (k < j)
		{
			if ((argv[i][k] >= 'a' && argv[i][k] <= 'z'))
				return (0);
			if ((argv[i][k] >= 'A' && argv[i][k] <= 'Z'))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

static int	check_doubles(t_stack_node *node)
{
	t_stack_node	*temp;

	temp = NULL;
	while (node)
	{
		temp = node->next;
		while (temp)
		{
			if (node->nbr == temp->nbr)
			{
				ft_printf("Error: \nDuplicates found\n");
				return (0);
			}
			temp = temp->next;
		}
		node = node->next;
	}
	return (1);
}

t_stack_node	*checks(int argc, char **numbers)
{
	t_stack_node	*node;

	if (argc < 2)
		return (NULL);
	node = create_list(numbers);
	if (!node)
		return (free_list_error(numbers), NULL);
	free_str_list(numbers);
	node = get_first_node(node);
	if (!check_doubles(node))
	{
		std_errror("Duplicates were found");
		return (free_node_list(node), NULL);
	}
	set_indexes(node);
	return (node);
}
