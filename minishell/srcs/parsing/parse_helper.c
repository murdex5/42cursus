/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:01:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/31 12:01:41 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	word_len(t_token *token)
{
	int		len;
	t_token	*current;

	len = 0;
	current = token;
	while (current != NULL)
	{
		switch (current->type)
		{
		case TOKEN_WORD:
			len++;
			break ;
		}
		current = current->next;
	}
	return (len);
}

int	list_len(t_token *token)
{
	int len;
	t_token *current;

	current = token;
	while (current != NULL)
	{
		i++;
		current = current->next
	}
	return (i);
}

