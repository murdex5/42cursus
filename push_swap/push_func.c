/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:02:47 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/24 10:03:13 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	pb(int *a, int *b)
{
	int	*temp_b;
	int	a_len;
	int	b_len;
	int	i;
	int	i;
	int	i;

	a_len = int_arr_len(a);
	b_len = int_arr_len(b);
	if ((sizeof(b) / sizeof(int)) >= 1)
		b_len += 1;
	temp_b = malloc(sizeof(int) * b_len);
	if (!temp_b)
		return (0);
	if ((sizeof(b) / sizeof(int)) >= 1)
	{
		temp_b[b_len] = a[a_len];
		b_len--;
	}
	while (b_len > 0)
	{
		temp_b[b_len] = b[b_len];
		b_len--;
	}
	return (1);
}*/
static void	dealloc_arr(int **a, int *len)
{
    int i;

    if (!*(a) || *(len) == 0)
        return ;
    i = 1;
    while (i < *(len))
    {
        *(a)[i-1] = *(a)[i];
        i++;
    }
    *(len)--;
    *a = ft_realloc(a, (*(len) * sizeof(int)));
    if (*len > 0 && *a == NULL)
        *len = 0;
}

// int	pa(int **a, int **b, int *a_len, int *b_len)
// {
	
// }
