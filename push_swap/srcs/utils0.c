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

#include "../push_swap.h"

int	int_arr_len(int *arr)
{
	size_t	len;

	if (arr)
		len = sizeof(&arr) / sizeof(int);
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

int	check_numbers(char *c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(c);
	j = 0;
	while (i < len)
	{
		if (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
			j = 0;
		if (c[i] >= '0' && c[i] <= '9')
			j = 0;
		j++;
		i++;
	}
	if (j >= 2)
		return (0);
	else
		return (1);
}

int	get_items(char const *s, char c)
{
	int	cur;
	int	word_num;

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

void	*ft_realloc(void *a, size_t new_size)
{
	void	*new_ptr;

	if (!a)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(a);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, a, new_size);
	free(a);
	return (new_ptr);
}
