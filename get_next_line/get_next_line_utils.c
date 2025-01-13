/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:08:16 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/13 16:08:17 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(t_list *list)
{
	int	i;

	i = 0;
	while (list->buff[i])
	{
		if (list->buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	append(char **list, char *buf)
{
	t_list	*new_list;
	t_list	*last_list;

	last_list = find_last_node(*list);
	new_list = malloc(sizeof(t_list));
	if (NULL == new_list)
		return ;
	if (last_list == NULL)
		*list = new_list;
	else
		last_list->next = new_list;
	new_list->buff = buf;
	new_list->next = NULL;
}

t_list	*find_last_node(t_list *list)
{
	t_list	*temp;

	if (list == NULL)
		return (NULL);
	temp = list;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

size_t	get_len_lists(t_list *list)
{
	int	i;
	int	l;

	i = 0;
	while (list)
	{
		l = 0;
		while (list->buff[l])
		{
			if (list->buff[l] == '\n')
			{
				++i;
				return (i);
			}
			++l;
		}
		i += l;
		list = list->next;
	}
	return (i);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buff[i])
		{
			if (list->buff[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
			}
			str[k++] = list->buff[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

void	dealloc(t_list **list, t_list *node, char *buf)
{
	t_list	*tmp;

	if (buf)
		free(buf);
	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buff);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (node->buff[0])
		*list = node;
	else
	{
		free(node);
	}
}
