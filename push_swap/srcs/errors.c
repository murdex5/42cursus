/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:24:03 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/05 10:24:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list_error(char **numbers)
{
	free_str_list(numbers);
	std_errror("List creation failed!");
}

void	std_errror(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
}
