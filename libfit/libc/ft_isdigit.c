/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <kadferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:21:48 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/09 16:25:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int ft_isdigit(char c)
{
    if (!(c >= '0' && c <= '9'))
        return (1);
    return (0);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    else
    {
        if (ft_isdigit(av[1][0]) == 0)
            printf("is digit\n");
        else
            printf("not digit\n");
    }
    return 0;
}*/