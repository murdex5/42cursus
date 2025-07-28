/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:40:07 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/28 11:40:08 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_on_exiting_list(t_token *tokens)
{
	t_token *current;
	t_token *next;

	if (tokens == NULL)
		return ;
	current = tokens;
	while (tokens != NULL)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}