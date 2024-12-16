/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:02:15 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/16 11:02:19 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list   *lst)
{
    int i;
    t_list *temp;

    i = 0;
    temp = lst;
    while (temp!= NULL)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}
