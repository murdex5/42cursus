/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:14:42 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/31 11:14:44 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**create_list(t_token *token)
{
	char	**list;
	int		i;
	int		token_len;
	int		j;
	t_token	*current;

	token_len = list_len();
	current = token;
	list = malloc(sizeof(char *) * (word_len(token) + 1));
	if (!list)
		return (NULL);
	i = 0;
	j = 0;
	while (i < token_len)
	{
		switch (current->type)
		{
		case TOKEN_WORD:
			list[j] = current->value;
			j++;
			break ;
		}
		i++;
	}
	return (list);
}
