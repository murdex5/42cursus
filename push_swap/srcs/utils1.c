/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:31:26 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/24 10:31:28 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*get_first_node(t_stack_node *node)
{
	while (node && node->prev)
		node = node->prev;
	return (node);
}

t_stack_node	*get_last_node(t_stack_node *node)
{
	t_stack_node	*current;

	current = node;
	while (current && (current->next != NULL))
		current = current->next;
	return (current);
}

void	set_indexes(t_stack_node *node)
{
	int				i;
	t_stack_node	*current;

	current = get_first_node(node);
	i = 0;
	while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

int	get_len_except(char *num)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (num[i] != '\0')
	{
		if (num[i] != '+' || num[i] != '-')
		{
			i++;
			len++;
		}
		else
			i++;
	}
	return (len);
}

char	**malloc_and_set_null(int len)
{
	char	**s;
	int		i;

	s = malloc(sizeof(char *) * len);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = NULL;
		i++;
	}
	return (s);
}

int	check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 && str[i + 1] == 32)
			return (0);
		ft_printf("i execured\n");
		i++;
	}
	return (1);
}