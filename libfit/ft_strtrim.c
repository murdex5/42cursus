/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:41:55 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 17:41:58 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

static int isin(char c, char const *set)
{
    int i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *result;
    size_t trim_len;
    size_t i;

    i = 0;
    trim_len = ft_strlen(s1);
    while (s1[i] != '\0')
    {
        if (isin(s1[i], set))
        {
            trim_len--;
        }
        i++;
    }
    result = malloc(sizeof(char) * trim_len + 1)
}