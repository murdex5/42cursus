/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:42:06 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/31 10:42:07 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	std_err_msg(char *msg)
{
	printf("Error\n %s\n", msg);
}

void report_syntax_error(char *msg, t_token *token)
[
	printf("%s: %s\n", msg, token->value);
]