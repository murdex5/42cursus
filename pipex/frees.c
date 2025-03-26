/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:10:28 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 11:10:30 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_arr(char ***str_arr, int i)
{
	int	j;
	int	l;

	while (i > 0)
	{
		j = 0;
		while (str_arr[i][j] != NULL)
		{
			free(str_arr[i][j]);
			j++;
		}
		i--;
	}
	free(str_arr);
	return (1);
}
