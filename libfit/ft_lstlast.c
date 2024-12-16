/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:23:24 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/16 11:23:25 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    int len;
    int i;
    t_list  *last;

    i = 0;
    len = ft_lstsize(lst);
    last = lst;
    while (i <  len - 1)
    {
        last = last->next;
        i++;
    }
    return (last);
}
