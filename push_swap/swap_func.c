/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:45:27 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 11:45:57 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb(int *a, int *b)
{
    int *temp_b;

	int a_len = int_arr_len(a);
	int b_len = int_arr_len(b);
	if (b >= 1)
		b_len += 1;
    temp_b = malloc(sizeof(int) * b_len);
    if (!temp_b)
        return (0);
    if (b >= 1)
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
}
