/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <kadferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:49:30 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/09 16:16:55 by kadferna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int ft_isalpha(char c)
{
    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
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
        if (ft_isalpha(av[1][0]) == 0)
            printf("is alpha\n");
        else
            printf("not alpha\n");
    }
    return 0;
}*/