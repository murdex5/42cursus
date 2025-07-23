/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:32:34 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/12 17:32:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(char *r1)
{
	printf("exit\n");
	free_r1(r1);
}

void	*ft_realloc(void *a, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!new_size)
	{
		free(a);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (a)
	{
		copy_size = old_size < new_size ? old_size : new_size;
		ft_memcpy(new_ptr, a, copy_size);
		free(a);
	}
	return (new_ptr);
}

// int	chec_char(char *c)
// {
// 	if (line[i] != ' ')
// 	{
// 		if (line)
// 	}
// }

// void	go_until(char *line, int *i)
// {
// 	if ()
// }

// int	get_count(char *line)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		{
// 			while (((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a'
// 						&& line[i] <= 'z')))
// 				i++;
// 			count++;
// 		}
// 	}
// }
