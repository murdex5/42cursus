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

// int	main(int argc, char **argv, char *envp[])
// {
// 	int i = ft_atoi(argv[1]);
// 	printf("%d\n", i);
// 	return (argc);
// }

int	main(void)
{
	char *r1;

	while (1)
	{
		r1 = readline("Prompt > ");
		printf("%s\n", r1);
        if (ft_strncmp(r1, "exit", ft_strlen(r1)) == 0)
            break ;
	}
	return (0);
}