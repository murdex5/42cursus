/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <kadferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:49:30 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/09 15:55:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    else
    {
        if (ft_isalpha(av[1]) == 0)
            printf("is alpha\n");
        else
            printf("not alpha\n");
    }
    return 0;
}