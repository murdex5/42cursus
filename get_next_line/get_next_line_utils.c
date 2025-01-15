/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:50:36 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/15 10:50:38 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(t_list *list)
{
	int	i;

	i = 0;
	while (list->line[i])
	{
		if (list->line[i] == '\n')
			return (1);
	}
	return (0);
}

t_list	*find_last_node(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		temp = temp->next;
	}
	return (temp);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->line = buffer;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
	}
	last_node = find_last_node(list);
	last_node->next = new_node;
}

int	list_str_len(t_list *list)
{
	int	i;
	int	k;

	i = 0;
	while (list != NULL)
	{
		k = 0;
		while (list->line[k] != '\0')
			k++;
		i += k;
		list = list->next;
	}
	return (i);
}

void	copy_str(t_list *list, char *buffer)
{
	int	i;
	int	k;

	i = 0;
	if (!list)
		return ;
	while (list)
	{
		k = 0;
		while (list->line[k] && list->line[k] != '\n')
			buffer[i++] = list->line[k++];
		if (list->line[k] == '\n')
		{
			buffer[i++] = '\n';
			return ;
		}
		list = list->next;
	}
	buffer[i] = '\0';
}
