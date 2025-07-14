/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:32:23 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/12 17:32:26 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*r1;

	while (1)
	{
		r1 = NULL;
		r1 = readline("minishell> ");
		if (r1 == NULL)
			return (ft_exit(r1), 1);
		printf("%s\n", r1);
		free(r1);
	}
	return (0);
}
