/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:46:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 10:46:40 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_arr_len(int *arr)
{
	size_t	len;
	if (arr)
		len = sizeof(arr) / sizeof(arr[0]);
	else
		return (0);
	return ((int)len);
}

int	error_msg(void)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	get_items(char const *s, char c)
{
	int cur;
	int word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}