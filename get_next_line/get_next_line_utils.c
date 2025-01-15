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

	if (!list)
	{
        return (0);
    }
	i = 0;
	while (list->line[i])
	{
		if (list->line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp && temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!list || !buffer)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return ;
	}
	new_node->line = buffer;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last_node = find_last_node(*list);
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
		{
			if (list->line[k] == '\n')
			{
				i += k;
				return (i);
			}
			k++;
		}
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
			break ;
		}
		list = list->next;
	}
	buffer[i] = '\0';
}

void	dealloc(t_list *list)
{
	if (!list)
		return ;
	if (list->line)
		free(list->line);
	free(list);
}

void	polish_list(t_list **list)
{
	t_list	*current;
	t_list	*next;
	int		i;
	char	*leftover;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		i = 0;
		while (current->line[i] && current->line[i] != '\n')
			i++;
		if (current->line[i] == '\n')
		{
			i++;
			leftover = (current->line[i]) ? strdup(current->line + i) : NULL;
			if (current->line[i] && !leftover)
				return ;
			next = current->next;
			while (current)
			{
				next = current->next;
				dealloc(current);
				current = next;
			}
			*list = NULL;
			if (leftover)
				append(list, leftover);
			return ;
		}
		next = current->next;
		dealloc(current);
		current = next;
	}
	*list = NULL;
}
