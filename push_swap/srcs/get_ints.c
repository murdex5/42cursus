/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ints.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:04:11 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/20 14:06:36 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_if_ints(char *str)
{
    int	i;

    i = 0;
    if (!str || !*str) // Handle empty string case
        return (0);
    if (!check_spaces(str)) // check_spaces ensures no "  " (consecutive spaces)
        return (0);
    while (str[i] != '\0')
    {
        // Allow digits, signs (+, -), and single spaces.
        // Any other character is an error.
        if (str[i] != ' ' && str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

char	**get_ints(int argc, char **argv, int *len)
{
    char	**str_arr;
    int		i;
    int		count;

    i = 1;
    if (argc < 2)
        return (error_msg(), NULL);
    if (argc == 2)
    {
        if (argv[1] == NULL || argv[1][0] == '\0')
            return (error_msg(), NULL);
        str_arr = ft_split(argv[1], ' ');
        if (!str_arr)
            return (NULL);
        count = 0;
        while (str_arr[count] != NULL)
            count++;
        if (count == 0)
        {
            free_str_list(str_arr);
            return (error_msg(), NULL); // Indicate error for no valid numbers
        }
        *len = count;
        return (str_arr);
    }
    str_arr = malloc_and_set_null(argc);
    if (!str_arr)
        return (NULL);
    while (i < argc)
    {
        str_arr[i - 1] = ft_strdup(argv[i]);
        if (!str_arr[i - 1])
            return (free_str_list(str_arr), NULL);
        i++;
    }
    str_arr[argc - 1] = NULL;
    *len = argc - 1;
    return (str_arr);
}

char	**get_int_checks(int argc, char **argv, int *len)
{
	char	**str;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!check_if_ints(argv[i]))
			return (0);
		i++;
	}

	str = get_ints(argc, argv, len);
	if (!str)
		return (NULL);
	return (str);
}
